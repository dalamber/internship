cmake_minimum_required(VERSION 2.8.12)

project(masonry)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/lib)
add_subdirectory (lib)
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/app)
add_subdirectory (app)
