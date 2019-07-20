#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QFileDialog>
#include <QtGui/QTextCursor>
#include <QtCore/QProcess>
#include <filesystem>
#include "GeneratedFiles/ui_romtool.h"

class romtool : public QMainWindow
{
	Q_OBJECT

public:
	romtool(QWidget *parent = Q_NULLPTR);

private slots:
	void inputSelect();
	void outputSelect();
	void extract();
	void stopThread();
	void postExtract();

	void cxi_entry();
	void bin_entry();

private:
	QProcess *cia_process;
	QProcess *cxi_process;
	QProcess *rom_process;
	QProcess *exe_process;

	bool run_flag;
	Ui::MainWindow ui;
	std::filesystem::path inputFilepath;
	std::filesystem::path outputDirectoryPath;
	std::filesystem::path tmpDirectoryPath;

	void consoleWrite(std::string text);
	void process_entrypoint(std::filesystem::path input);
	void cia_extract(std::filesystem::path input);
	void cxi_extract(std::filesystem::path input);
	void romfs_extract(std::filesystem::path input);
	void exefs_extract(std::filesystem::path input);
};
