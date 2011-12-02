#include "DownloadManager.h"

#include "YoutubeInterface.h"

#include <QString>
#include <QEventLoop>
#include <QFile>
#include <QUrl>
#include <QNetworkAccessManager>

DownloadManager::DownloadManager(QNetworkAccessManager *manager, const YoutubeInterface *yti)
{
	this->manager = manager;
	this->yti = yti;

	setRawHeader("User-Agent", "clipcrawler");
}

void DownloadManager::writeToFile()
{
	//(*outputStream) << reply->readAll();
	emit statusMessage("Write message");
}

void DownloadManager::downloadTo(const QString &dir)
{
	QEventLoop loop;
	QFile target(dir + "/" + yti->getVideoTitle() + "." + yti->getVideoFormat());

	if(!target.open(QIODevice::WriteOnly))
	{
		emit statusMessage("Cannot open file.");
		return;
	}

	//outputStream = new QTextStream(&target);

	setUrl(QUrl(yti->getVideoUrl()));
	reply = manager->get(*this);

	emit statusMessage("Download file '" + target.fileName() + "' from url '" + yti->getVideoUrl() + "' ...");
	QObject::connect(reply, SIGNAL(readyRead()), this,  SLOT(writeToFile()));
	QObject::connect(reply, SIGNAL(finished()),  &loop, SLOT(quit()));
	loop.exec();
	emit statusMessage("Download finished! (return code " + QString::number(reply->error()) + ")");

	target.close(); // close file stream
	//delete outputStream;
}
