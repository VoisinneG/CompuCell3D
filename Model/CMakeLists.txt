cmake_minimum_required(VERSION 3.8)

find_package(Qt5Core PATHS /usr/local/Cellar/qt/5.9.1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SRCS
        CompuCellModel.cpp
        modelresoucedata.cpp
        resourcetype.cpp
        Simulator.cpp)

add_library(Model STATIC ${SRCS})

target_link_libraries(Model Qt5::Core)