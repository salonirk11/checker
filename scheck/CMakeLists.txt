cmake_minimum_required(VERSION 2.8)
project( scheck )
set (CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SRC_DIR} inc)
add_library(parser src/parser.cpp)

add_executable( scheck src/main.cpp )
target_link_libraries( scheck parser )
