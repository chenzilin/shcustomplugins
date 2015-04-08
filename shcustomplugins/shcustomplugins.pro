# QtCreator Plugin Pro
# By chenzilin
# Email:chenzilin115@gmail.com

TEMPLATE = lib
QT += widgets designer

CONFIG += plugin debug_and_release
TARGET = $$qtLibraryTarget(shcustomplugins)

HEADERS += shcustomplugins.h
SOURCES += shcustomplugins.cpp
RESOURCES += shcustomplugins.qrc

cross_compiler{
    message(Please pay attention to cross-plateform  compile)
}else{
    message(Make with designer plugin)
}

#dirs names of sub_directory
PLUGIN_SRCDIRS =  shanalogclock shratetable shslider \
    shdigitdate shdigitclock sharrows

#search for every sub-directory
for(dir, PLUGIN_SRCDIRS){
    DEPENDPATH += $${dir}

    prifile = $${dir}/$${dir}.pri
    exists($$prifile){
        include($$prifile)
    }
}

DESTDIR = bin
UI_DIR = build
MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build

headers.files = $$INCHEADERS
headers.path = $$[QT_INSTALL_HEADERS]/SHQtCustom
INSTALLS += headers

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target
