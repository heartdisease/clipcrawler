#include "MainWindow.h"

MainWidget::MainWidget(QWidget* parent) : QWidget(parent)
{
	setupUi(this);
}

MainWindow::MainWindow(int width, int height)
{
	centralWidget = new MainWidget(this);
	setCentralWidget(centralWidget);
	setBaseSize(width, height);
	setMinimumSize(width, height);
	setWindowTitle("clipcrawler 0.1dev1");
}
