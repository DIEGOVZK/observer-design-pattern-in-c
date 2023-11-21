cmake_minimum_required(VERSION 3.12)
project(observer-design-pattern-in-c C)

include(FetchContent)
FetchContent_Declare(
    UNITY
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/UNITY.git
    GIT_TAG        v2.5.2
)

if(NOT UNITY_POPULATED)
    FetchContent_Populate(UNITY)
    add_subdirectory(build/_deps/unity-src build/_deps/unity-build)
endif()

add_executable(executable
    src/main.c
)

target_link_libraries(executable PRIVATE UNITY)
target_include_directories(executable PRIVATE
    include
    build/_deps/unity-src/src
)