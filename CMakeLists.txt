cmake_minimum_required(VERSION 3.12)
project(FileCompression)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(FileCompression
        src/ByteToken.cpp
        src/ByteToken.h
        src/Constants.h
        src/Huffman.cpp
        src/Huffman.h
        src/Main.cpp
        src/Menu.cpp
        src/Menu.h
        src/Node.cpp
        src/Node.h
        src/Utils.cpp
        src/Utils.h src/DecodingNode.cpp src/DecodingNode.h)
