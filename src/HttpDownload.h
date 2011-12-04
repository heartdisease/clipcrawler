#ifndef CLIPCRAWLER_HTTP_DOWNLOAD_H__
#define CLIPCRAWLER_HTTP_DOWNLOAD_H__

#include <QString>
#include <QUrl>
#include <QTcpSocket>

class QNetworkAccessManager;

class HttpDownload : public QTcpSocket
{
	Q_OBJECT

	signals:
		void statusMessage(const QString&);

	private:
		QNetworkAccessManager *manager;
		QString downloadPath;
		QUrl url;

	private slots:
		void writeData();

	public:
		HttpDownload(QNetworkAccessManager *manager);
		void setUrl(const QUrl &url);
		void setDownloadPath(const QString &path);
		bool download();
};

#endif
