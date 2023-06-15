cmake_minimum_required(VERSION 3.12)
project(wutil)
option(WUTIL_BUILD_SHARED OFF)
set(WUTIL_SRC
  src/wstring.cpp
)

if(WUTIL_BUILD_SHARED)
  add_library(wutil SHARED ${WUTIL_SRC})
  target_compile_definitions(wutil PRIVATE WUTIL_SHARED_BUILDING)
  target_compile_definitions(wutil PUBLIC WUTIL_SHARED)
else()
  add_library(wutil STATIC ${WUTIL_SRC})
endif()

target_compile_features(wutil PUBLIC cxx_std_20)
target_include_directories(wutil PUBLIC include)