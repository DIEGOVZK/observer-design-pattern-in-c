cmake_minimum_required(VERSION 3.12)
project(observer-design-pattern-in-c C)

include(FetchContent)
FetchContent_Declare(
  Unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG        v2.5.2
)

FetchContent_GetProperties(Unity)
if(NOT Unity_POPULATED)
  FetchContent_Populate(Unity)
  add_subdirectory(${Unity_SOURCE_DIR} ${Unity_BINARY_DIR})
endif()