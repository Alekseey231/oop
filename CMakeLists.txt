cmake_minimum_required(VERSION 3.5)

project(lab_03 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        objects/BaseObject.h
        objects/BaseObject.cpp
        objects/composite.h
        objects/invisible_object/InvisibleObject.h
        objects/visible_object/BaseModel.h
        objects/visible_object/VisibleObject.h
        objects/visible_object/carcas_model/CarcasModel.cpp
        objects/visible_object/carcas_model/CarcasModel.h
        objects/visible_object/carcas_model/edge.cpp
        objects/visible_object/carcas_model/edge.h
        objects/visible_object/carcas_model/figure.cpp
        objects/visible_object/carcas_model/figure.h
        objects/visible_object/carcas_model/point.h
        objects/visible_object/carcas_model/point.cpp
        visitor/BaseVisitor.h
        matrix/matrix/matrix.h
        matrix/matrix/matrix.hpp
        matrix/matrix/matrix_base.cpp
        matrix/matrix/matrix_base.hpp
        matrix/iterator/const_matrix_iterator.h
        matrix/iterator/const_matrix_iterator.hpp
        matrix/iterator/matrix_iterator.h
        matrix/iterator/matrix_iterator.hpp
        matrix/errors/errors.cpp
        matrix/errors/errors.hpp
        drawer/BaseGraphicsScene.h
        drawer/GraphicsFactory.h
        drawer/QtGraphicsFactory.h
        drawer/QtGraphicsScene.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(lab_03
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET lab_03 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(lab_03 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(lab_03
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(lab_03 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(lab_03 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(lab_03)
endif()
