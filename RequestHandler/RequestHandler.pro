#-------------------------------------------------
#
# Project created by QtCreator 2017-08-14T15:20:26
#
#-------------------------------------------------

QT       -= gui

TARGET = RequestHandler
TEMPLATE = lib

DEFINES += REQUESTHANDLER_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        requesthandler.cpp

HEADERS += \
        requesthandler.h \
        requesthandler_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Model/release/ -lModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Model/debug/ -lModel
else:unix: LIBS += -L$$OUT_PWD/../Model/ -lModel

INCLUDEPATH += $$PWD/../Model
DEPENDPATH += $$PWD/../Model


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../IO/release/ -lIO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../IO/debug/ -lIO
else:unix: LIBS += -L$$OUT_PWD/../IO/ -lIO

INCLUDEPATH += $$PWD/../IO
DEPENDPATH += $$PWD/../IO

