#include "romtool.h"
#include <QtWidgets/QApplication>
#include <QtPlugin>
Q_IMPORT_PLUGIN (QWindowsIntegrationPlugin);
Q_IMPORT_PLUGIN(QWindowsVistaStylePlugin);

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	romtool w;
	w.show();
	return a.exec();
}
