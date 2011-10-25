project(testguiapp)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(testguiapp_SRCS testguiapp.cpp main.cpp)
qt4_automoc(${testguiapp_SRCS})
add_executable(testguiapp ${testguiapp_SRCS})
target_link_libraries(testguiapp ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
