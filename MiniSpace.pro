QT       += core gui opengl widgets openglwidgets
TEMPLATE = app
CONFIG += c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
else {
        LIBS     += -lGL -lGLU
}

TARGET = MiniSpace

SOURCES += \
    asteroid.cpp \
    main.cpp \
    spacewidget.cpp \
    webcam.cpp

HEADERS += \
    asteroid.h \
    spacewidget.h \
    webcam.h

FORMS += \
    webcam.ui

RESOURCES += \
    Resources/textures.qrc

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
