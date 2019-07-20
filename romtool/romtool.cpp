#include "romtool.h"

romtool::romtool(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.cancel_button->setEnabled(false);
	connect(ui.input_button, SIGNAL(clicked()), this, SLOT(inputSelect()));
	connect(ui.output_button, SIGNAL(clicked()), this, SLOT(outputSelect()));
	connect(ui.extract_button, SIGNAL(clicked()), this, SLOT(extract()));
	connect(ui.cancel_button, SIGNAL(clicked()), this, SLOT(stopThread()));
}

void romtool::inputSelect()
{
	QString input = QFileDialog::getOpenFileName(this, "Select input file...", QDir::homePath(), "Supported Types(*.cia *.cxi *.ncch *.bin);;All Files(*)");
	if (input != "") 
		ui.input_text->setText(input);
}

void romtool::outputSelect()
{
	QString output = QFileDialog::getExistingDirectory(this, "Select output directory...", QDir::homePath());
	if (output != "")
		ui.output_text->setText(output);
}

void romtool::consoleWrite(std::string text) {
	ui.console_out->append(QString::fromStdString(text));
}

void romtool::stopThread() {
	ui.cancel_button->setEnabled(false);
	consoleWrite("Stopping Program...");
	run_flag = false;
}

void romtool::postExtract() {
	ui.input_text->setEnabled(true);
	ui.input_button->setEnabled(true);
	ui.output_text->setEnabled(true);
	ui.output_button->setEnabled(true);
	ui.exefs_select->setEnabled(true);
	ui.tmp_select->setEnabled(true);
	ui.extract_button->setEnabled(true);
	ui.cancel_button->setEnabled(false);
	consoleWrite("|------------------------- ALL DONE! -----------------------|");
	if (ui.tmp_select->isChecked()) {
		consoleWrite("Temp folder located at: " + tmpDirectoryPath.string());
		if (std::filesystem::exists(tmpDirectoryPath.append("decrypt.exe"))) {
			std::filesystem::remove(tmpDirectoryPath.append("decrypt.exe"));
		}
	}
	else {
		std::filesystem::remove_all(tmpDirectoryPath);
	}
}

void romtool::extract()
{
	inputFilepath = std::filesystem::path(ui.input_text->text().toStdString());
	outputDirectoryPath = std::filesystem::path(ui.output_text->text().toStdString());

	bool error = false;
	if (std::filesystem::exists(inputFilepath) == false) {
		consoleWrite("[ERROR] Invalid input file!");
		error = true;
	}
	if (std::filesystem::exists(outputDirectoryPath) == false) {
		consoleWrite("[ERROR] Invalid output directory!");
		error = true;
	}
	if (!std::filesystem::exists("tools/decrypt.exe")) {
		consoleWrite("[ERROR] decrypt.exe missing from tools directory!");
		error = true;
	}
	if (!std::filesystem::exists("tools/ctrtool.exe")) {
		consoleWrite("[ERROR] ctrtool missing from tools directory!");
		error = true;
	}
	if (!std::filesystem::exists("tools/3dstool.exe")) {
		consoleWrite("[ERROR] 3dstool missing from tools directory!");
		error = true;
	}
	if (error) {
		return;
	}
	else {
		ui.input_text->setEnabled(false);
		ui.input_button->setEnabled(false);
		ui.output_text->setEnabled(false);
		ui.output_button->setEnabled(false);
		ui.exefs_select->setEnabled(false);
		ui.tmp_select->setEnabled(false);
		ui.extract_button->setEnabled(false);
		ui.cancel_button->setEnabled(true);

		tmpDirectoryPath = outputDirectoryPath / std::filesystem::path(outputDirectoryPath.stem().string() + "-tmp");
		create_directory(tmpDirectoryPath);
		process_entrypoint(inputFilepath);
	}
}

void romtool::process_entrypoint(std::filesystem::path input) {
	run_flag = true;
	if (input.extension() == ".cia") {
		cia_extract(input);
	}
	else if (input.extension() == ".cxi" || input.extension() == ".ncch") {
		cxi_extract(input);
	}
	else if (input.filename() == "romfs.bin") {
		romfs_extract(input);
	}
	else if (input.filename() == "exefs.bin") {
		exefs_extract(input);
	}
	else {
		consoleWrite("[ERROR] Unsupported type");
		postExtract();
	}
}

void romtool::cia_extract(std::filesystem::path input) {
	consoleWrite("|---------------------- Decrypting cia ---------------------|");

	std::filesystem::copy("tools/decrypt.exe", tmpDirectoryPath);
	std::filesystem::path decrypt = tmpDirectoryPath / "decrypt.exe";

	cia_process = new QProcess(this);
	cia_process->setProcessChannelMode(QProcess::MergedChannels);
	QStringList arguments;
	arguments << QString::fromStdString(inputFilepath.string());
	connect(cia_process, &QProcess::readyReadStandardOutput, [=]() { ui.console_out->append(cia_process->readAllStandardOutput()); });
	connect(cia_process, QOverload<int>::of(&QProcess::finished), this, &romtool::cxi_entry);

	cia_process->start(QString::fromStdString(decrypt.string()), arguments);
	cia_process->write("f\n");
}

void romtool::cxi_entry() {
	if (run_flag) {
		std::filesystem::path output = tmpDirectoryPath / (inputFilepath.stem() += ".0.ncch");
		cxi_extract(output);
	}
	else {
		postExtract();
	}
}

void romtool::cxi_extract(std::filesystem::path input) {
	consoleWrite("|--------------- Converting cxi to bin files ---------------|");
	cxi_process = new QProcess(this);
	cxi_process->setProcessChannelMode(QProcess::MergedChannels);
	QStringList arguments;
	arguments << "-xvtf" << "cxi" << QString::fromStdString(input.string()) << "--romfs" << 
		QString::fromStdString((tmpDirectoryPath / "romfs.bin").string());
	if (ui.exefs_select->isChecked()) {
		arguments << "--exefs" << QString::fromStdString((tmpDirectoryPath / "exefs.bin").string());
	}
	connect(cxi_process, &QProcess::readyReadStandardOutput, [=]() { ui.console_out->append(cxi_process->readAllStandardOutput()); });
	connect(cxi_process, QOverload<int>::of(&QProcess::finished), this, &romtool::bin_entry);

	cxi_process->start("./tools/3dstool", arguments);
}

void romtool::bin_entry() {
	if (run_flag) {
		std::filesystem::path output = tmpDirectoryPath / "romfs.bin";
		romfs_extract(output);
		if (ui.exefs_select->isChecked()) {
			output = tmpDirectoryPath / "exefs.bin";
			exefs_extract(output);
		}
	}
	else {
		postExtract();
	}
}

void romtool::romfs_extract(std::filesystem::path input) {
	consoleWrite("|------------------ Unpacking bin file(s) ------------------|");
	rom_process = new QProcess(this);
	rom_process->setProcessChannelMode(QProcess::MergedChannels);
	QStringList arguments;
	arguments << "--intype=romfs" << "--romfsdir=" + QString::fromStdString((outputDirectoryPath / "romfsdir").string()) << QString::fromStdString(input.string());
	connect(rom_process, &QProcess::readyReadStandardOutput, [=]() { ui.console_out->append(rom_process->readAllStandardOutput()); });
	connect(rom_process, QOverload<int>::of(&QProcess::finished), this, &romtool::postExtract);

	rom_process->start("./tools/ctrtool", arguments);
}

void romtool::exefs_extract(std::filesystem::path input) {
	exe_process = new QProcess(this);
	exe_process->setProcessChannelMode(QProcess::MergedChannels);
	QStringList arguments;
	arguments << "--intype=exefs" << "--exefsdir=" + QString::fromStdString((outputDirectoryPath / "exefsdir").string()) << QString::fromStdString(input.string());
	connect(exe_process, &QProcess::readyReadStandardOutput, [=]() { ui.console_out->append(rom_process->readAllStandardOutput()); });

	exe_process->start("./tools/ctrtool", arguments);
}
