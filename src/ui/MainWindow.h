#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include "ui_main.h"

#include <QMainWindow>
#include <QWidget>

class MainWidget : public QWidget, private Ui::MainWidget
{
	public:
		MainWidget(QWidget *parent);
};

class MainWindow : public QMainWindow
{
	private:
		MainWidget *centralWidget;

	public:
		MainWindow(int width, int height);
};

#endif
