#ifndef CLIPCRAWLER_DOWNLOAD_MANAGER_H__
#define CLIPCRAWLER_DOWNLOAD_MANAGER_H__

#include <QObject>
#include <QFile>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTextStream>

class QString;
class QNetworkAccessManager;
class YoutubeInterface;

class DownloadManager : public QObject, public QNetworkRequest
{
	Q_OBJECT

	private:
		QNetworkReply *reply;
		QTextStream *outputStream;
		const YoutubeInterface *yti;
		QNetworkAccessManager *manager;

	signals:
		void statusMessage(const QString&);

	private slots:
		void writeToFile();

	public:
		DownloadManager(QNetworkAccessManager *manager, const YoutubeInterface *yti);
		void downloadTo(const QString &dir);
};

#endif
