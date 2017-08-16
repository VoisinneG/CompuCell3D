#-------------------------------------------------
#
# Project created by QtCreator 2017-08-07T16:17:07
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI
TEMPLATE = app

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
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

#------------------------ Model Library ------------------------
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Model/release/ -lModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Model/debug/ -lModel
else:unix: LIBS += -L$$OUT_PWD/../Model/ -lModel

INCLUDEPATH += $$PWD/../Model
DEPENDPATH += $$PWD/../Model

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Model/release/libModel.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Model/debug/libModel.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Model/release/Model.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Model/debug/Model.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Model/libModel.a
#------------------------------------------------------------

#-------- IO Library -------------------------
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../IO/release/ -lIO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../IO/debug/ -lIO
else:unix: LIBS += -L$$OUT_PWD/../IO/ -lIO

INCLUDEPATH += $$PWD/../IO
DEPENDPATH += $$PWD/../IO

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../IO/release/libIO.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../IO/debug/libIO.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../IO/release/IO.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../IO/debug/IO.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../IO/libIO.a
#------------------------------------------------

#------------------------ RequestHandler Library ------------------------------------
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../RequestHandler/release/ -lRequestHandler
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../RequestHandler/debug/ -lRequestHandler
else:unix: LIBS += -L$$OUT_PWD/../RequestHandler/ -lRequestHandler

INCLUDEPATH += $$PWD/../RequestHandler
DEPENDPATH += $$PWD/../RequestHandler

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../RequestHandler/release/libRequestHandler.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../RequestHandler/debug/libRequestHandler.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../RequestHandler/release/RequestHandler.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../RequestHandler/debug/RequestHandler.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../RequestHandler/libRequestHandler.a
#------------------------------------------------------------------------------------
