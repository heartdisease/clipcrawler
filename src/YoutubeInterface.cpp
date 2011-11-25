#include "YoutubeInterface.h"

#include <QString>
#include <QRegExp>
#include <QNetworkReply>
#include <QEventLoop>

YoutubeInterface::YoutubeInterface(QNetworkAccessManager *manager)
{
	this->manager = manager;
	setRawHeader("User-Agent", "clipcrawler");
}

void YoutubeInterface::fetchUrl(QString url)
{
	QNetworkReply *reply;
	QEventLoop loop;

	id = url.remove(QRegExp("^.*v="));
	videoUrl = "http://www.youtube.com/get_video_info?&video_id=" + id;

	setUrl(QUrl(videoUrl));
	reply = manager->get(*this);

	emit statusMessage("Download from '" + videoUrl + "' ...");

	// wait until download has ended
	QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec();

	emit statusMessage("data dump: [" + QString(reply->readAll()) + "]");
	emit statusMessage(QString::number(reply->error()));
}

const QString &YoutubeInterface::getVideoUrl()
{
	return videoUrl;
}

const QString &YoutubeInterface::getVideoTitle()
{
	return videoTitle;
}
