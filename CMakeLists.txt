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

add_executable(testWordCounter
    test/wordCounter.test.c
    include/observer/observer.c
    include/wordsHandler/wordCounter.c
)

add_executable(testSubjectStructure
    test/subject.structure.test.c
    include/observer/observer.c
)

target_link_libraries(executable PRIVATE unity)
target_link_libraries(testWordCounter PRIVATE unity)
target_link_libraries(testSubjectStructure PRIVATE unity)

target_include_directories(executable PRIVATE
    include/observer
    include/wordsHandler
)

target_include_directories(testWordCounter PRIVATE
    include/observer
    include/wordsHandler
    ${unity_SOURCE_DIR}/src
)

target_include_directories(testSubjectStructure PRIVATE
    include/observer
    ${unity_SOURCE_DIR}/src
)

add_custom_target(run_tests
    COMMAND ${CMAKE_COMMAND} --build . --target testWordCounter && ./testWordCounter
    COMMAND ${CMAKE_COMMAND} --build . --target testSubjectStructure && ./testSubjectStructure
    DEPENDS testWordCounter testSubjectStructure
)