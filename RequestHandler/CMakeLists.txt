cmake_minimum_required(VERSION 3.8)

include_directories(../)


find_package(Qt5Core PATHS ${QT_PATH})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SRCS
        requesthandler.cpp)

add_library(RequestHandler STATIC ${SRCS})

target_link_libraries(RequestHandler Qt5::Core BasicUtils Model IO XMLUtils)