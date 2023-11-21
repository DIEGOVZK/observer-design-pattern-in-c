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

add_executable(test
    test/subject.structure.test.c
    include/observer/observer.c
)

target_link_libraries(executable PRIVATE unity)
target_link_libraries(test PRIVATE unity)

target_include_directories(executable PRIVATE
    include/observer
    include/wordsHandler
)

target_include_directories(test PRIVATE
    include/observer
    include/wordsHandler
    ${unity_SOURCE_DIR}/src
)

add_custom_target(run_tests
    COMMAND test
    DEPENDS test
)