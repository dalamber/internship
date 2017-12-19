cmake_minimum_required(VERSION 2.8.12)

project(masonry)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(SOURCE container.cpp imageitem.cpp main.cpp mymainwidget.cpp)
set(HEADER container.h imageitem.h item.h mymainwidget.h)

find_package(Qt5Core)
find_package (Qt5Widgets)

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::QSize)
target_link_libraries(${PROJECT_NAME} Qt5::QApplication)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
