#-------------------------------------------------
#
# Project created by QtCreator 2014-08-17T14:30:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = minarea_qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


#edit this path's to your system path in opencv
INCLUDEPATH += D:\\OCV\\opencv\\build\\include
LIBS += -LD:\\OCV\\opencv\\build\\x64\\vc12\\lib \
        -lopencv_core249d \
        -lopencv_imgproc249d


