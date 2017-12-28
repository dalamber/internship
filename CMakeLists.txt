cmake_minimum_required(VERSION 2.8.12)

project(masonry)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(MASONRY_SRCS container.cpp
        imageitem.cpp
        main.cpp
	mycustomwidget.cpp
        mymainwidget.cpp
	webimagewidget.cpp
        container.h
        imageitem.h
        item.h
	mycustomwidget.h
        mymainwidget.h
	webimagewidget.h)

set (MASONRY_LIBS Qt5::Core Qt5::Network Qt5::Widgets)

find_package (Qt5Core)
find_package (Qt5Network)
find_package (Qt5Widgets)


add_executable(${PROJECT_NAME} ${MASONRY_SRCS})
target_link_libraries(${PROJECT_NAME} ${MASONRY_LIBS})
