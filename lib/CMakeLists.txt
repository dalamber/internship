add_library(mystaticlib STATIC container.cpp container.h item.h)

set (MY_LIBS Qt5::Core Qt5::Network Qt5::Widgets)

find_package (Qt5Core)
find_package (Qt5Network)
find_package (Qt5Widgets)

target_link_libraries(mystaticlib ${MY_LIBS})
