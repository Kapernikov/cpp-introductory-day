cmake_minimum_required(VERSION 3.1)

project(exercises CXX)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)
option(ENABLE_SOLUTIONS "Enable the model solutions" OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    add_definitions(-Wall -Wextra -Werror)
    add_definitions(-Wno-unused)    # Suppress unused warnings
endif()

set(BIN_DIRECTORY bin)

find_package(SFML)
add_library(sfml INTERFACE)
target_include_directories(sfml SYSTEM INTERFACE ${SFML_INCLUDE_DIRS})
target_link_libraries(sfml INTERFACE ${SFML_LIBRARIES})
link_directories(${SFML_LIBRARY_DIRS})

add_subdirectory(utils)
add_subdirectory(session1)
add_subdirectory(session2)
add_subdirectory(session3)
