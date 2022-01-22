QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets core

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/callback.cpp \
    src/http_client.cpp \
    src/httpclient.cpp \
    src/imagewidget.cpp \
    main.cpp \
    src/mainwindow.cpp \
    src/network.c \
    src/test.cpp \

HEADERS += \
    include/callback.h \
    include/lib/developermode.hpp \
    include/http_client.h \
    include/http_client.h \
    include/imagewidget.h \
    include/mainwindow.h \
    include/network.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    DAC_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

VERSION = 1.2.3.4

DEFINES += APP_VERSION=\\\"$$VERSION\\\"


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
