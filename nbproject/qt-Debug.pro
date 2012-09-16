# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-MacOSX
TARGET = QtApplication_1
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui
SOURCES += main.cpp formulari.cpp matching_to_many_images.cpp
HEADERS += formulari.h
FORMS += formulari.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-MacOSX
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += /opt/local/include/opencv2 /opt/local/include/opencv /opt/local/include 
LIBS += -I/usr/local/include/opencv -L/usr/local/lib -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_features2d -lopencv_legacy -lopencv_imgproc -lopencv_contrib -lopencv_nonfree   
