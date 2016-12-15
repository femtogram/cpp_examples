cmake_minimum_required(VERSION 2.8)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)

set(SRC
  src/main.cpp)

add_executable(cpp_examples ${SRC})

add_custom_target(run
  COMMAND __PROEJCT-NAME__
  DEPENDS cpp_examples
  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
