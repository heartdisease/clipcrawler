/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created: Sat Nov 12 14:18:47 2011
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
    QWidget *widget;
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
        MainWidget->resize(414, 311);
        widget = new QWidget(MainWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 411, 311));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        urlField = new QLineEdit(widget);
        urlField->setObjectName(QString::fromUtf8("urlField"));

        gridLayout->addWidget(urlField, 0, 2, 1, 2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        downloadField = new QLineEdit(widget);
        downloadField->setObjectName(QString::fromUtf8("downloadField"));

        gridLayout->addWidget(downloadField, 1, 2, 1, 1);

        browseButton = new QPushButton(widget);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));

        gridLayout->addWidget(browseButton, 1, 3, 1, 1);

        downloadButton = new QPushButton(widget);
        downloadButton->setObjectName(QString::fromUtf8("downloadButton"));

        gridLayout->addWidget(downloadButton, 2, 0, 1, 4);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 3, 0, 1, 4);

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
