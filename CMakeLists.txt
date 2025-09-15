cmake_minimum_required(VERSION 3.15)
project(SKYBOUND C)

add_subdirectory(raylib)

set(SOURCES
    src/main.c
    src/player.c    
)

add_executable(Skybound ${SOURCES})

target_link_libraries(Skybound PRIVATE raylib)