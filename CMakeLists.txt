cmake_minimum_required(VERSION 3.12)
project(observer-design-pattern-in-c C)

include(FetchContent)
FetchContent_Declare(
    UNITY
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/UNITY.git
    GIT_TAG        v2.5.2
)

FetchContent_MakeAvailable(UNITY)

add_executable(executable
    src/main.c
)

target_link_libraries(executable PRIVATE unity)
target_include_directories(executable PRIVATE
    include
    ${unity_SOURCE_DIR}/src
)