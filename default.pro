TARGET = clipcrawler
CONFIG += debug_and_release

MOC_DIR = moc
UI_DIR = src/ui

CONFIG(debug, debug|release) {
	DESTDIR = bin/debug
	OBJECTS_DIR = obj/debug
}
CONFIG(release, debug|release) {
	DESTDIR = bin/release
	OBJECTS_DIR = obj/release
}

