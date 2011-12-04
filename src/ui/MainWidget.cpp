#include "MainWidget.h"

#include "YoutubeInterface.h"
#include "DownloadManager.h"
#include "HttpDownload.h"

#include <QString>
#include <QDir>
#include <QUrl>
#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QNetworkAccessManager>

MainWidget::MainWidget(QWidget* parent) : QWidget(parent)
{
	manager = new QNetworkAccessManager(this);

	setupUi(this);
	urlField->setText("http://www.youtube.com/watch?v=oB8fcZCxiC8");
	downloadField->setText("/home/heartdisease");
	QObject::connect(downloadButton, SIGNAL(clicked()), this, SLOT(startDownload()));
	QObject::connect(browseButton, SIGNAL(clicked()), this, SLOT(searchDirectory()));
}

void MainWidget::appendStatusMessage(const QString &msg)
{
	textEdit->append(msg);
}

void MainWidget::searchDirectory()
{
	QString dir = QFileDialog::getExistingDirectory(
		this, tr("Choose download directory ..."),
		QString(),
		QFileDialog::ShowDirsOnly
    );
    downloadField->setText(dir);
}

bool MainWidget::checkUserInput()
{
	if (urlField->text().isEmpty() || !QUrl(urlField->text()).isValid())
	{
		QMessageBox::information(this, tr("Invalid user input"), tr("Invalid URL!"));
		urlField->setFocus(Qt::OtherFocusReason);
		urlField->selectAll();
		return false;
	}
	if (downloadField->text().isEmpty() || !QDir(downloadField->text()).exists())
	{
		QMessageBox::information(this, tr("Invalid user input"), tr("Download directory does not exist!"));
		downloadField->setFocus(Qt::OtherFocusReason);
		downloadField->selectAll();
		return false;
	}

	return true;
}

void MainWidget::startDownload()
{
	YoutubeInterface yti(manager);
	DownloadManager dm(manager, &yti);
	//HttpDownload dl(manager);

	if (checkUserInput())
	{
		downloadButton->setEnabled(false);

		connect(&yti, SIGNAL(statusMessage(const QString&)), this, SLOT(appendStatusMessage(const QString&)));
		connect(&dm,  SIGNAL(statusMessage(const QString&)), this, SLOT(appendStatusMessage(const QString&)));
		//connect(&dl, SIGNAL(statusMessage(const QString&)), this, SLOT(appendStatusMessage(const QString&)));

		yti.fetchUrl(urlField->text());
		dm.downloadTo(downloadField->text());
		//dl.setDownloadPath(downloadField->text());
		//dl.setUrl(QUrl(yti.getVideoUrl()));
		//dl.download();

		downloadButton->setEnabled(true);
	}
}
