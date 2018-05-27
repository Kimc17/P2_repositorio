cmake_minimum_required(VERSION 3.9)
project(Main)

set(CMAKE_CXX_STANDARD 11)

add_executable(Main base64.cpp base64.h Chunk.cpp Chunk.h MostrarXML.h  Oddysey_server.cpp Oddysey_server.h pugixml.cpp)