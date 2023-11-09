cmake_minimum_required(VERSION 3.11)
project(cpp_study VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-fshort-wchar)

# include(CTest)
# enable_testing()
set(BUILD_TESTING OFF)
include(FetchContent)
FetchContent_Declare(
  Fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt"
  GIT_TAG "7.1.3"
  )
FetchContent_MakeAvailable(Fmt)

# include(FetchContent)
# FetchContent_Declare(
#     tbb
#     GIT_REPOSITORY "https://github.com/oneapi-src/oneTBB"
#     GIT_TAG "v2021.2.1"
# )
# FetchContent_MakeAvailable(tbb)

include(FetchContent)
FetchContent_Declare(
  Poco
  GIT_REPOSITORY "https://github.com/pocoproject/poco.git"
  GIT_TAG "poco-1.11.8-release"
)
# FetchContent_MakeAvailable(Poco)
FetchContent_GetProperties(Poco)
if(NOT poco_POPULATED)
  FetchContent_Populate(Poco)
  # target_compile_definitions(Poco INTERFACE SQL_WCHART_CONVERT)  
  # set(SQL_WCHART_CONVERT ON)
  
  add_subdirectory(${poco_SOURCE_DIR} ${poco_BINARY_DIR} EXCLUDE_FROM_ALL)
  set_property(DIRECTORY ${poco_SOURCE_DIR} APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS SQL_WCHART_CONVERT)
endif()

file(GLOB studycpp ./*.cpp)

add_executable(cpp_study main.cpp ${studycpp})
target_link_libraries(cpp_study fmt pthread Poco::Data Poco::DataODBC Poco::Foundation)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
