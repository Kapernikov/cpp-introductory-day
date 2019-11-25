cmake_minimum_required(VERSION 3.1)

project(exercises CXX)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)
list(APPEND CMAKE_MODULE_PATH /usr/share/SFML/cmake/Modules)
option(ENABLE_SOLUTIONS "Enable the model solutions" OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    add_definitions(-Wall -Wextra -Werror)
    add_definitions(-Wno-unused)    # Suppress unused warnings
endif()

set(BIN_DIRECTORY bin)

if(MSVC)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

if(NOT SFML_DIR)
    set(SFML_DIR /usr/bin/sfml)
endif()
find_package(SFML REQUIRED COMPONENTS graphics window system)
add_library(sfml INTERFACE)
target_include_directories(sfml SYSTEM INTERFACE sfml-graphics sfml-window sfml-system)
target_link_libraries(sfml INTERFACE sfml-graphics sfml-window sfml-system)

add_subdirectory(utils)
add_subdirectory(exercises)
