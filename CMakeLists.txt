cmake_minimum_required(VERSION 3.25)

project(
    nekketsu-soccer-league
    VERSION 1.0
    HOMEPAGE_URL "https://github.com/enetheru/godot-cpp-template/tree/main"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(libs)
add_subdirectory(project/gdextension)