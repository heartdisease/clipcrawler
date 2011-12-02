#include "MainWidget.h"

#include <QString>
#include <QWidget>
#include <QNetworkAccessManager>

#include "YoutubeInterface.h"
#include "DownloadManager.h"

MainWidget::MainWidget(QWidget* parent) : QWidget(parent)
{
	manager = new QNetworkAccessManager(this);

	setupUi(this);
	urlField->setText("http://www.youtube.com/watch?v=HA0FDThGP-M"); // debug only
	downloadField->setText("/media/Data/youtube/neu");
	QObject::connect(downloadButton, SIGNAL(clicked()), this, SLOT(startDownload()));
}

void MainWidget::appendStatusMessage(const QString &msg)
{
	textEdit->append(msg);
}

void MainWidget::startDownload()
{
	YoutubeInterface yti(manager);
	DownloadManager dm(manager, &yti);

	connect(&yti, SIGNAL(statusMessage(const QString&)), this, SLOT(appendStatusMessage(const QString&)));
	connect(&dm,  SIGNAL(statusMessage(const QString&)), this, SLOT(appendStatusMessage(const QString&)));

	yti.fetchUrl(urlField->text());
	dm.downloadTo(downloadField->text());
}
