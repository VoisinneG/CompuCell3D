cmake_minimum_required(VERSION 3.8)

include_directories(../)


find_package(Qt5Core PATHS /usr/local/Cellar/qt/5.9.1)
find_package(Qt5Xml PATHS /usr/local/Cellar/qt/5.9.1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SRCS
        cc3dreader.cpp
        modelreader.cpp)

add_library(IO STATIC ${SRCS})

target_link_libraries(IO Model Qt5::Core Qt5::Xml XMLUtils)