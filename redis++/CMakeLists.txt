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

find_library(HIREDIS_LIB hiredis REQUIRED)
find_path(HIREDIS_HEADER hiredis REQUIRED)

include(FetchContent)
FetchContent_Declare(
    redis_plus_plus
    GIT_REPOSITORY "https://github.com/sewenew/redis-plus-plus"
    GIT_TAG "1.3.10"
)
if(NOT redis_plus_plus_POPULATED)
    FetchContent_Populate(redis_plus_plus)
    add_subdirectory(${redis_plus_plus_SOURCE_DIR} ${redis_plus_plus_BINARY_DIR} EXCLUDE_FROM_ALL)
    set_property(DIRECTORY ${redis_plus_plus_SOURCE_DIR} APPEND PROPERTY COMPILE_DEFINITIONS -DREDIS_PLUS_PLUS_BUILD_TEST=OFF)
endif()
FetchContent_MakeAvailable(redis_plus_plus)
add_executable(main main.cpp)
target_include_directories(main PUBLIC ${HIREDIS_HEADER} ${redis_plus_plus_SOURCE_DIR}/src)
target_link_libraries(main PUBLIC ${HIREDIS_LIB} redis++_static)
