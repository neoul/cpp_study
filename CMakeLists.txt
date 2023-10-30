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

file(GLOB studycpp ./*.cpp )

add_executable(cpp_study main.cpp ${studycpp})
target_link_libraries(cpp_study fmt pthread)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
