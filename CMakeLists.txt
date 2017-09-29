cmake_minimum_required(VERSION 3.8)

project(CompuCell3D)

set(QT_PATH /usr/local/Cellar/qt/5.9.1)

add_subdirectory(BasicUtils)
add_subdirectory(Model)
add_subdirectory(XMLUtils)
add_subdirectory(IO)
add_subdirectory(RequestHandler)
add_subdirectory(UI)




#set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES main.cpp)
#add_executable(CompuCell3D UI)