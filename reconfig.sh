#!/bin/bash
if [ -f Makefile ]
then
	make clean
fi

qmake -project
echo "include(default.pro)" >> clipcrawler.pro
qmake
