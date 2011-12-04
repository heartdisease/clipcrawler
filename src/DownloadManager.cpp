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

	setRawHeader("User-Agent", "Mozilla/5.0 (Windows NT 6.1; rv:5.0) Gecko/20100101 Firefox/5.0");
	setRawHeader("Accept-Charset", "utf-8");
	setRawHeader("Accept-Language", "en-US");
}

void DownloadManager::writeToFile()
{
	QByteArray data = reply->readAll();

	outputFile->write(data.data(), data.size());
}

void DownloadManager::downloadTo(const QString &dir)
{
	QEventLoop loop;
	outputFile = new QFile(dir + "/" + yti->getVideoTitle() + "." + yti->getVideoFormat());

	if(!outputFile->open(QIODevice::WriteOnly))
	{
		emit statusMessage("ERROR: Cannot open file!");
		return;
	}

	setUrl(
		QUrl(
			QUrl::fromPercentEncoding(yti->getVideoUrl().toAscii()) // fromPercentEncoding() is very important here!
		)
	);
	reply = manager->get(*this);

	emit statusMessage("Download from url '" + yti->getVideoUrl() + "' to file '" + outputFile->fileName() + "' ...");
	QObject::connect(reply, SIGNAL(readyRead()), this, SLOT(writeToFile()));
	QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec();
	emit statusMessage("Download finished! (return code " + QString::number(reply->error()) + ")");

	outputFile->close(); // close file stream
	delete outputFile;
}
