QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = MiniSpace
TEMPLATE = app

SOURCES += \
    asteroid.cpp \
    main.cpp \
    webcam.cpp

HEADERS += \
    asteroid.h \
    webcam.h

FORMS += \
    webcam.ui

INCLUDEPATH +=$$(OPENCV_DIR)\..\..\include

LIBS += -L$$(OPENCV_DIR)\lib \
    -lopencv_core455 \
    -lopencv_highgui455 \
    -lopencv_imgproc455 \
    -lopencv_imgcodecs455 \
    -lopencv_videoio455 \
    -lopencv_features2d455 \
    -lopencv_calib3d455 \
    -lopencv_objdetect455
