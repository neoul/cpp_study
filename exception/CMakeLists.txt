cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# project name and language
project(hello LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(REDIS_PLUS_PLUS_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  poco
  GIT_REPOSITORY "https://github.com/pocoproject/poco.git"
  GIT_TAG "poco-1.11.8-release"
)
FetchContent_MakeAvailable(poco)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC Poco::Foundation)
