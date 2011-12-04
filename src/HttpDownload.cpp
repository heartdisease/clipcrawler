#include "HttpDownload.h"

#include <QObject>
#include <QString>
#include <QUrl>
#include <QEventLoop>

#define BUFFER_LENGTH 1024

#include <iostream>

void HttpDownload::writeData()
{
	char buffer[BUFFER_LENGTH];
	qint64 len = readData(buffer, BUFFER_LENGTH);

	emit statusMessage(QString(buffer));
	std::cout << buffer << std::flush;
}

HttpDownload::HttpDownload(QNetworkAccessManager *manager)
{
	this->manager = manager;
}

void HttpDownload::setUrl(const QUrl &url)
{
	this->url = url;
}

void HttpDownload::setDownloadPath(const QString &path)
{
	this->downloadPath = path;
}

bool HttpDownload::download()
{
	const QString httpHeader(
		"GET " + this->url.path() + "?" + QUrl::fromPercentEncoding(this->url.encodedQuery()) +
		" HTTP/1.1\r\nHost: " + this->url.host() +
		"\r\n\r\n"
	);
	QEventLoop loop;

	std::cout << "URL: " << this->url.host().toAscii().data() << this->url.encodedPath().data() << "?" << this->url.encodedQuery().data() << std::endl;
	std::cout << httpHeader.toAscii().data() << std::endl;

	QObject::connect(this, SIGNAL(readyRead()), this, SLOT(writeData()));
	QObject::connect(this, SIGNAL(disconnected()), &loop, SLOT(quit()));

	connectToHost(this->url.host(), 80);
	write(httpHeader.toAscii());
	flush();
	loop.exec();

	std::cout << "Connection closed." << std::endl;

	return true;
}
