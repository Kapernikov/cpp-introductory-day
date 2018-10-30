set(LIB_NAME solutions-session1)
set(LIB_SOURCES
    smartBall.cpp
    bat.cpp
)

add_library(${LIB_NAME} ${LIB_SOURCES})
target_link_libraries(${LIB_NAME} PUBLIC sfml utils)

set(BIN_SOURCES
    exercise-1.1.cpp
    exercise-1.2.cpp
    exercise-1.3.cpp
    exercise-1.4.cpp
    exercise-1.5.cpp
)

set(DEPS
    utils
    solutions-session1
    sfml
)

foreach(SOURCE IN ITEMS ${BIN_SOURCES})
    string (REPLACE ".cpp" "" TARGET "${SOURCE}")
    add_executable(${TARGET} ${SOURCE})
    target_include_directories(${TARGET} PRIVATE ${DEPS})
    target_link_libraries(${TARGET} PRIVATE ${DEPS})

    install(TARGETS ${TARGET} DESTINATION ${BIN_DIRECTORY})
endforeach(SOURCE)
