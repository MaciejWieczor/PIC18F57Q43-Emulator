QT += core
QT += widgets
QT += gui

HEADERS += headers/*.h
SOURCES += src/*.cpp
FORMS += ui/main_window.ui

CONFIG += qwt
INCLUDEPATH += headers
BUILD_DIR = ./build
OBJECTS_DIR = ./.objects
MOC_DIR = ./.moc
RCC_DIR = ./.rcc
UI_DIR = ./.ui
QMAKE_CXXFLAGS_WARN_ON = -Wno-unused-parameter
