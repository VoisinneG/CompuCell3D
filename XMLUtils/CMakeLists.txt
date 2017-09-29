cmake_minimum_required(VERSION 3.8)

include_directories(../)

add_subdirectory(Expat_2.2.4)

set(SRCS
        XMLParserExpat.cpp
        CC3DXMLElement.cpp
        CC3DXMLElementWalker.cpp)

add_library(XMLUtils STATIC ${SRCS})

target_link_libraries(XMLUtils BasicUtils expat)