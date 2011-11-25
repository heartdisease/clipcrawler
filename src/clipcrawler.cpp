#include "ui/MainWindow.h"

#include <QApplication>

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	MainWindow root(550, 300);
	root.show();

	return app.exec();
}
