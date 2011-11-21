/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created: Mon Nov 21 13:23:10 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *urlField;
    QLabel *label_2;
    QLineEdit *downloadField;
    QPushButton *browseButton;
    QPushButton *downloadButton;
    QTextEdit *textEdit;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(512, 333);
        gridLayout = new QGridLayout(MainWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(MainWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        urlField = new QLineEdit(MainWidget);
        urlField->setObjectName(QString::fromUtf8("urlField"));

        gridLayout->addWidget(urlField, 0, 1, 1, 2);

        label_2 = new QLabel(MainWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        downloadField = new QLineEdit(MainWidget);
        downloadField->setObjectName(QString::fromUtf8("downloadField"));

        gridLayout->addWidget(downloadField, 1, 1, 1, 1);

        browseButton = new QPushButton(MainWidget);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));

        gridLayout->addWidget(browseButton, 1, 2, 1, 1);

        downloadButton = new QPushButton(MainWidget);
        downloadButton->setObjectName(QString::fromUtf8("downloadButton"));
        downloadButton->setMinimumSize(QSize(0, 44));

        gridLayout->addWidget(downloadButton, 2, 0, 1, 3);

        textEdit = new QTextEdit(MainWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 3, 0, 1, 3);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(urlField);
        label_2->setBuddy(downloadField);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWidget", "URL:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWidget", "Download to:", 0, QApplication::UnicodeUTF8));
        browseButton->setText(QString());
        downloadButton->setText(QApplication::translate("MainWidget", "Download", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H
