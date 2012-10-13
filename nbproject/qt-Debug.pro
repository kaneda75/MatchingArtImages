# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-MacOSX
TARGET = MatchingArtImages
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui
SOURCES += HelloForm.cpp main.cpp matchingImages.cpp
HEADERS += matchingImages.hpp HelloForm.h
FORMS += HelloForm.ui
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
LIBS += -L/usr/local/include/opencv -L/usr/local/lib -L/opt/local/lib  -lopencv_core -lopencv_objdetect -lopencv_highgui -lopencv_features2d -lopencv_legacy -lopencv_imgproc -lopencv_contrib -lopencv_nonfree  
