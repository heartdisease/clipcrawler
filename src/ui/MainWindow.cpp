#include "MainWindow.h"

#include "MainWidget.h"

MainWindow::MainWindow(int width, int height)
{
	setCentralWidget(new MainWidget(this));
	setBaseSize(width, height);
	setMinimumSize(width, height);
	setWindowTitle("clipcrawler 0.1dev4");
}
