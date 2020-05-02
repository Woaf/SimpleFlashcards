QT -= gui

CONFIG += c++11
CONFIG -= app_bundle

RC_ICONS = appicon.ico

DEFINES += QT_DEPRECATED_WARNINGS

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        card.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
	card.h

QT += widgets

DISTFILES += \
	appicon.ico \
	examples/dict.txt \
	examples/verbs.txt
