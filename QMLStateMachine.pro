TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    appcontroller.cpp \
    state.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    appcontroller.h \
    state.h
