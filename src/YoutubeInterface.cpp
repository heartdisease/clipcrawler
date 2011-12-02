#include "YoutubeInterface.h"

#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QUrl>
#include <QNetworkReply>
#include <QEventLoop>

YoutubeInterface::YoutubeInterface(QNetworkAccessManager *manager)
{
	this->manager = manager;
	setRawHeader("User-Agent", "clipcrawler");
}

/**
_available_formats = ['38', '37', '22', '45', '35', '34', '43', '18', '6', '5', '17', '13']
_video_extensions = {
	'13': '3gp',
	'17': 'mp4',
	'18': 'mp4',
	'22': 'mp4',
	'37': 'mp4',
	'38': 'video', # You actually don't know if this will be MOV, AVI or whatever
	'43': 'webm',
	'45': 'webm',
}
*/
void YoutubeInterface::fetchUrl(QString url)
{
	QNetworkReply *reply;
	QEventLoop loop;
	QByteArray queryData;
	QStringList urlList;
	QString currUrl;
	QUrl querySet;

	id = url.remove(QRegExp("^.*v="));
	videoUrl = "http://www.youtube.com/get_video_info?&video_id=" + id;

	setUrl(QUrl(videoUrl));
	reply = manager->get(*this);

	emit statusMessage("Download from '" + videoUrl + "' ...");

	// wait until download has ended
	QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec();
	queryData = reply->readAll();
	querySet.setEncodedQuery(queryData);

	videoTitle = querySet.queryItemValue("title").replace("+", "_");
	videoFormat = "webm";

	//emit statusMessage("Connection exit code: " + QString::number(reply->error()));
	//emit statusMessage("title = " + videoTitle);
	//emit statusMessage("fmt_list = " + querySet.queryItemValue("fmt_list"));

	urlList = querySet.queryItemValue("url_encoded_fmt_stream_map").split(QRegExp("(url=)|(,)"), QString::SkipEmptyParts);
	int i = 0;
	for (QStringListIterator iter(urlList); iter.hasNext(); )
	{
		currUrl = QUrl::fromPercentEncoding(iter.next().toAscii());
		if (currUrl.contains("&fallback_host"))
			currUrl.truncate(currUrl.indexOf("&fallback_host"));
		videoUrl = currUrl;

		//emit statusMessage("[encoded] stream_map[" + QString::number(i) + "] = " + tmp);
		//emit statusMessage("[decoded] stream_map[" + QString::number(i) + "] = " + videoUrl);
		++i;
		break;
	}
}

const QString &YoutubeInterface::getVideoUrl() const
{
	return videoUrl;
}

const QString &YoutubeInterface::getVideoTitle() const
{
	return videoTitle;
}

const QString &YoutubeInterface::getVideoFormat() const
{
	return videoFormat;
}
