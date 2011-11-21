#include "ui/MainWindow.h"

#include <QApplication>

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	MainWindow root(400, 250);
	root.show();

	return app.exec();
}
