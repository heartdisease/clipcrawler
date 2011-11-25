#ifndef CLIPCRAWLER_YOUTUBE_INTERFACE_H__
#define CLIPCRAWLER_YOUTUBE_INTERFACE_H__

#include <QString>
#include <QNetworkRequest>

class QNetworkAccessManager;

class YoutubeInterface : public QObject, public QNetworkRequest
{
	Q_OBJECT

	private:
		QString id;
		QString videoUrl;
		QString videoTitle;
		QNetworkAccessManager *manager;

	signals:
		void statusMessage(const QString&);

	public:
		YoutubeInterface(QNetworkAccessManager *manager);
		void fetchUrl(QString url);
		const QString &getVideoUrl();
		const QString &getVideoTitle();
};

#endif
