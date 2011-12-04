#include "YoutubeInterface.h"

#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QUrl>
#include <QNetworkReply>
#include <QEventLoop>

static QStringList elType;

YoutubeInterface::YoutubeInterface(QNetworkAccessManager *manager)
{
	this->manager = manager;
	setRawHeader("User-Agent", "clipcrawler");

	elType.append("&el=embedded");
	elType.append("&el=detailpage");
	elType.append("&el=vevo");
	elType.append("");
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
	QUrl querySet; // used as utility for parsing the query string
	QUrl videoInfoUrl;

	this->id = url.remove(QRegExp("^.*v="));
	for (QStringListIterator iter(elType); iter.hasNext(); videoInfoUrl = QUrl("http://www.youtube.com/get_video_info?video_id=" + id + iter.next()))
	{
		setUrl(videoInfoUrl);
		reply = manager->get(*this);

		// fetch whole get_video_info
		QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
		loop.exec();
		queryData = reply->readAll();
		querySet.setEncodedQuery(queryData);

		// check if video info is valid
		if (querySet.hasQueryItem("token") && querySet.hasQueryItem("url_encoded_fmt_stream_map"))
		{
			videoTitle = querySet.queryItemValue("title").replace("+", "_");
			videoFormat = "webm";

			//emit statusMessage("Connection exit code: " + QString::number(reply->error()));
			//emit statusMessage("title = " + videoTitle);
			//emit statusMessage("fmt_list = " + querySet.queryItemValue("fmt_list"));

			urlList = querySet.queryItemValue("url_encoded_fmt_stream_map").split(QRegExp("(url=)|(,)"), QString::SkipEmptyParts);
			for (QStringListIterator iter(urlList); iter.hasNext(); )
			{
				videoUrl = QUrl::fromPercentEncoding(iter.next().toAscii());
				if (videoUrl.contains("&fallback_host"))
					videoUrl.truncate(videoUrl.indexOf("&fallback_host"));
				break; // take the first element
			}

			emit statusMessage("Extract video url '" + videoUrl + "' ...");
			return;
		}
	}

	emit statusMessage("ERROR: Cannot extract video url!");
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
