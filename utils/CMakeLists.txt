set(LIB_NAME utils)
set(LIB_SOURCES
    pongUtils.cpp
    movableRetangle.cpp
)

add_library(${LIB_NAME} ${LIB_SOURCES})
target_include_directories(${LIB_NAME} PUBLIC .)
target_link_libraries(${LIB_NAME} PUBLIC sfml)
