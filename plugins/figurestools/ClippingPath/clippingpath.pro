######################################################################
#         ClippingPath build script. Maxim Finojenok 2015
######################################################################

TEMPLATE = lib
TARGET = ClippingPath
CONFIG += plugin
QT += opengl xml xmlpatterns
DEPENDPATH += ./../../../pluginTool
INCLUDEPATH += ./../../../pluginTool
LIBS += -L./../../../pluginTool
DESTDIR = ./../../../bin/plugins/ClippingPath
RESOURCES += ClippingPath.qrc
HEADERS += ClippingPath.h \
    ../../../pluginTool/SignalHolder.h \
    ../../../pluginTool/Plugin.h
SOURCES += ClippingPath.cpp
