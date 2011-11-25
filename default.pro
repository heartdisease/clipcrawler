QT += network

TARGET = clipcrawler
CONFIG += debug_and_release

MOC_DIR = moc
UI_DIR = src/ui

CONFIG(debug, debug|release) {
	DESTDIR = bin/Debug
	OBJECTS_DIR = obj/Debug
}
CONFIG(release, debug|release) {
	DESTDIR = bin/Release
	OBJECTS_DIR = obj/Release
}

