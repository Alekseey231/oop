cmake_minimum_required(VERSION 3.5)

project(3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
find_package(glm REQUIRED)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        drawer/BaseGraphicsScene.h
        drawer/GraphicsFactory.h
        drawer/GraphicsSolution.h
        drawer/QtGraphicsFactory.h
        drawer/QtGraphicsScene.cpp
        drawer/QtGraphicsScene.h
        managers/BaseManager.h
        managers/cameramanager.cpp
        managers/cameramanager.h
        managers/drawmanager.cpp
        managers/drawmanager.h
        managers/managersolution.cpp
        managers/managersolution.h
        managers/scenemanager.cpp
        managers/scenemanager.h
        managers/transformmanager.cpp
        managers/transformmanager.h
        math/glm_wrapped.cpp
        math/glm_wrapped.h
        math/math.h
        math/transformation.cpp
        math/transformation.h
        objects/BaseObject.cpp
        objects/BaseObject.h
        objects/composite.cpp
        objects/composite.h
        objects/invisible_object/BaseCamera.h
        objects/invisible_object/Camera.cpp
        objects/invisible_object/Camera.h
        objects/invisible_object/InvisibleObject.h
        objects/visible_object/BaseModel.h
        objects/visible_object/VisibleObject.h
        objects/visible_object/carcas_model/CarcasModel.cpp
        objects/visible_object/carcas_model/CarcasModel.h
        objects/visible_object/carcas_model/edge.cpp
        objects/visible_object/carcas_model/edge.h
        objects/visible_object/carcas_model/figure.cpp
        objects/visible_object/carcas_model/figure.h
        scene/scene.cpp
        scene/scene.h
        visitor/BaseVisitor.h
        visitor/drawvisitor.cpp
        visitor/drawvisitor.h
        visitor/TransformVisitor.cpp
        visitor/TransformVisitor.h
        command/base_command.h
        command/object_command.cpp
        command/object_command.h
        objects/invisible_object/CameraSolution.h
        objects/invisible_object/CameraSolution.cpp
        facade/facade.h
        facade/facade.cpp
        exceptions/BaseExceptions.h
        exceptions/LoaderExceptions.h
        load/FileCarcasModelLoader.h
        load/FileCarcasModelLoader.cpp
        load/BaseDirector.h
        load/BaseLoader.h
        load/BaseModelBuilder.h
        load/FileModelDirector.h
        load/BaseModelDirector.h
        load/FileModelDirector.cpp
        load/ModelBuilder.cpp
        load/ModelBuilder.h
        load/SolutionModelLoadModerator.h
        load/SolutionModelLoadModerator.cpp
        load/ModelLoadModerator.h
        load/ModelLoadModerator.cpp
        managers/loadmanager.cpp
        )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(3
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET 3 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(3 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(3
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
enable_testing()

set_target_properties(3 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3)
endif()
