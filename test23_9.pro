QT       += core gui multimedia multimediawidgets network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data.cpp \
    lodier.cpp \
    main.cpp \
    mainwindowtest.cpp \
    mywidget.cpp \
    playvideo.cpp \
    register.cpp \
    viewingfilm.cpp \
    widget01.cpp

HEADERS += \
    data.h \
    lodier.h \
    mainwindowtest.h \
    mywidget.h \
    playvideo.h \
    register.h \
    viewingfilm.h \
    widget01.h

FORMS += \
    mainwindowtest.ui \
    playvideo.ui \
    register.ui \
    viewingfilm.ui \
    widget01.ui

TRANSLATIONS += \
    test23_9_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
