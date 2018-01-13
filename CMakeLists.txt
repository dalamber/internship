cmake_minimum_required(VERSION 2.8.12)

project(mystaticlib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(SOURCE_FILES container.cpp container.h item.h)

set (MASONRY_LIBS Qt5::Core Qt5::Network Qt5::Widgets)

find_package (Qt5Core)
find_package (Qt5Network)
find_package (Qt5Widgets)

add_library(mystaticlib STATIC ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${MASONRY_LIBS})
