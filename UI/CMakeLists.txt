cmake_minimum_required(VERSION 3.8)

include_directories(../)

find_package(Qt5Widgets PATHS ${QT_PATH} )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


add_library(mainwindow STATIC mainwindow.cpp)

target_link_libraries (mainwindow Qt5::Widgets RequestHandler BasicUtils)

add_executable(CompuCell3D main.cpp)

target_link_libraries (CompuCell3D mainwindow)
