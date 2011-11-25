#ifndef CLIPCRAWLER_MAIN_WIDGET_H__
#define CLIPCRAWLER_MAIN_WIDGET_H__

#include "ui_main.h"

#include <QWidget>

class QString;
class QNetworkAccessManager;

class MainWidget : public QWidget, private Ui::MainWidget
{
	Q_OBJECT

	private slots:
		void appendStatusMessage(const QString &msg);
		void startDownload();

	private:
		 QNetworkAccessManager *manager;

	public:
		MainWidget(QWidget *parent);
};

#endif
