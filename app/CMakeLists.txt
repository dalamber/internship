set(MASONRY_SRCS imageitem.cpp
        main.cpp
	mycustomwidget.cpp
        mymainwidget.cpp
        settingswidget.cpp
	webimagewidget.cpp    
        imageitem.h
	mycustomwidget.h
        mymainwidget.h
        settingswidget.h
	webimagewidget.h)

set (MASONRY_LIBS Qt5::Core Qt5::Network Qt5::Widgets)

find_package (Qt5Core)
find_package (Qt5Network)
find_package (Qt5Widgets)

add_executable(${PROJECT_NAME} ${MASONRY_SRCS})
target_link_libraries(${PROJECT_NAME} ${MASONRY_LIBS} mystaticlib)
