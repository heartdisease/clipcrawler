#include "MainWidget.h"

#include <QString>
#include <QWidget>
#include <QNetworkAccessManager>

#include "YoutubeInterface.h"

MainWidget::MainWidget(QWidget* parent) : QWidget(parent)
{
	manager = new QNetworkAccessManager(this);

	setupUi(this);
	urlField->setText("http://www.youtube.com/watch?v=HA0FDThGP-M"); // debug only
	QObject::connect(downloadButton, SIGNAL(clicked()), this, SLOT(startDownload()));
}

void MainWidget::appendStatusMessage(const QString &msg)
{
	textEdit->append(msg);
	textEdit->append("\n");
}

void MainWidget::startDownload()
{
	YoutubeInterface yti(manager);

	connect(&yti, SIGNAL(statusMessage(const QString&)), this, SLOT(appendStatusMessage(const QString&)));

	yti.fetchUrl(urlField->text());
	textEdit->append("startDownload()\n");
}
