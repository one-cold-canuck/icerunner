cmake_minimum_required (VERSION 3.2)

project(
    icerunner  # Project name, change this as needed.
    LANGUAGES CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")  # Keep all runtime files in one directory.

find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL2)
find_library(SDL2_LIBRARY NAME SDL2)

find_package(Curses REQUIRED)
find_package(SDL2 REQUIRED)


include_directories(${CURSES_INCLUDE_DIR})
include_directories(${SDL2_INCLUDE_DIRS})

file(
    GLOB_RECURSE SOURCE_FILES
    CONFIGURE_DEPENDS  # Automatically reconfigure if source files are added/removed.
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.hpp
    ${PROJECT_SOURCE_DIR}/src/*.h
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Ensure the C++17 standard is available.
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)


target_link_libraries(
    ${PROJECT_NAME} ${CURSES_LIBRARIES} ${SDL2_LIBRARIES})
