# By chenzilin
# Email:chenzilin115@gmail.com

QT += widgets

TARGET = shtest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += -L"/opt/Qt/Qt5.4.1/Tools/QtCreator/bin/plugins/designer" -lshcustomplugins

DESTDIR = bin
UI_DIR = build
MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build
