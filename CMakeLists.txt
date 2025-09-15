cmake_minimum_required(VERSION 3.15)
project(DOODLE_JUMP C)

add_subdirectory(raylib)

set(SOURCES
    src/main.c
    src/player.c    
)

add_executable(Doodle_Jump ${SOURCES})

target_link_libraries(Doodle_Jump PRIVATE raylib)