QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    asteroide.cpp \
    bala.cpp \
    drawable.cpp \
    gamelogic.cpp \
    gamewidget.cpp \
    main.cpp \
    mainwindow.cpp \
    ovni.cpp \
    pj.cpp \
    ui.cpp

HEADERS += \
    asteroide.h \
    bala.h \
    drawable.h \
    gamelogic.h \
    gamewidget.h \
    mainwindow.h \
    nave.h \
    ovni.h \
    pj.h \
    ui.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
