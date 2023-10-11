cmake_minimum_required(VERSION 3.11)
project(MyTest VERSION 0.1.0 LANGUAGES C CXX)

# include(CTest)
# enable_testing()
set(BUILD_TESTING OFF)

include(FetchContent)
FetchContent_Declare(
  tbb
  GIT_REPOSITORY "https://github.com/oneapi-src/oneTBB"
  GIT_TAG "v2021.2.3"
  )
FetchContent_MakeAvailable(tbb)

include(FetchContent)
FetchContent_Declare(
  Fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt"
  GIT_TAG "7.1.3"
  )
FetchContent_MakeAvailable(Fmt)

add_executable(MyTest main.cpp)
target_link_libraries(MyTest fmt tbb pthread)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
