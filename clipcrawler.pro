######################################################################
# Automatically generated by qmake (2.01a) So. Dez 4 14:25:55 2011
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . src ui src/ui
INCLUDEPATH += . src/ui src

# Input
HEADERS += src/DownloadManager.h \
           src/HttpDownload.h \
           src/YoutubeInterface.h \
           src/ui/MainWidget.h \
           src/ui/MainWindow.h
FORMS += ui/main.ui
SOURCES += src/clipcrawler.cpp \
           src/DownloadManager.cpp \
           src/HttpDownload.cpp \
           src/YoutubeInterface.cpp \
           src/ui/MainWidget.cpp \
           src/ui/MainWindow.cpp
RESOURCES += icons.qrc
include(default.pro)
