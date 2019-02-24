cmake_minimum_required(VERSION 2.6)

Project(PantherWM)

include_directories(${PantherWM_SOURCE_DIR}/include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

file(GLOB SOURCES "src/*.cpp")

find_package(PkgConfig)
pkg_check_modules(X11 REQUIRED x11)
pkg_check_modules(LIBGLOG REQUIRED libglog)

include_directories(${X11_INCLUDE_DIRS})
link_directories(${X11_LIBRARY_DIRS})
include_directories(${LIBGLOG_INCLUDE_DIRS})
link_directories(${LIBGLOG_LIBRARY_DIRS})

add_executable(PantherWM ${SOURCES})
add_definitions(${X11_CFLAGS_OTHER})
add_definitions(${LIBGLOG_CFLAGS_OTHER})
target_link_libraries(PantherWM ${X11_LIBRARIES} ${LIBGLOG_LIBRARIES})

