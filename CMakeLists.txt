cmake_minimum_required(VERSION 3.9)
project(Main)

set(CMAKE_CXX_STANDARD 11)

add_executable(Main main.cpp Base64.cpp Base64.h Chunk.cpp Chunk.h MostrarXML.h build/XML.cpp build/XML.h Oddysey_server.cpp Oddysey_server.h pugixml.cpp)