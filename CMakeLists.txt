cmake_minimum_required(VERSION 3.12)
project(observer-design-pattern-in-c C)

include(FetchContent)
FetchContent_Declare(
    UNITY
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/UNITY.git
    GIT_TAG        v2.5.2
)

FetchContent_MakeAvailable(UNITY)

set(SOURCES
    include/observer/observer.c
    include/wordsHandler/wordCounter.c
)

set(TESTS
    test/wordCounter.test.c
    test/subject.structure.test.c
)

foreach(test ${TESTS})
    get_filename_component(test_name ${test} NAME_WE)
    add_executable(${test_name} ${test} ${SOURCES})
    target_link_libraries(${test_name} PRIVATE unity)
    target_include_directories(${test_name} PRIVATE
        include/observer
        include/wordsHandler
        ${unity_SOURCE_DIR}/src
    )
endforeach()

add_executable(executable src/main.c ${SOURCES})
target_link_libraries(executable PRIVATE unity)
target_include_directories(executable PRIVATE
    include/observer
    include/wordsHandler
)

set(TEST_COMMANDS)
set(TEST_DEPENDENCIES)

foreach(test ${TESTS})
    get_filename_component(test_name ${test} NAME_WE)
    list(APPEND TEST_COMMANDS COMMAND ${CMAKE_COMMAND} --build . --target ${test_name} && ./${test_name})
    list(APPEND TEST_DEPENDENCIES ${test_name})
endforeach()

add_custom_target(run_tests
    ${TEST_COMMANDS}
    DEPENDS ${TEST_DEPENDENCIES}
)