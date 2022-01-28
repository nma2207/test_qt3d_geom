cmake_minimum_required(VERSION 3.14)

project(test_geometry VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Quick)
find_package(Qt6 COMPONENTS Quick3D)


qt_add_executable(apptest_geometry
    main.cpp
    mygeometry.h
    mygeometry.cpp
    mygeomtry2.h
    mygeomtry2.cpp
)

qt_add_qml_module(apptest_geometry
    URI TestGeometry
    VERSION 1.0
    QML_FILES main.qml 
)

target_compile_definitions(apptest_geometry
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(apptest_geometry
    PRIVATE Qt6::Quick
    Qt::Core
    Qt::Gui
    Qt::Quick3D)
