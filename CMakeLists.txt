include(FetchContent)

# Declare the external library
FetchContent_Declare(
  Unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG        v2.5.2
)

# Retrieve properties of the external library
FetchContent_GetProperties(Unity)

# Check if the library has already been populated
if(NOT Unity_POPULATED)
  FetchContent_Populate(Unity)
  add_subdirectory(${Unity_SOURCE_DIR} ${Unity_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
