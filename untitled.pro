QT       += core gui
QT       += core gui sql
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DatabaseManager.cpp \
    GameOverDialog.cpp \
    Global.cpp \
    HistoryScreen.cpp \
    SignInScreen.cpp \
    SignUpScreen.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    DatabaseManager.h \
    GameOverDialog.h \
    Global.h \
    HistoryScreen.h \
    SignInScreen.h \
    SignUpScreen.h \
    TicTacToeGame.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    images/images.qrc

DISTFILES += \
    images/WhatsApp Image 2024-06-26 at 3.57.17 PM.jpeg
