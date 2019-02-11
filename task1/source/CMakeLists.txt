cmake_minimum_required(VERSION 2.8)

project(task1)

include_directories( ${MY_SOURCE_DIR}/source )

add_executable(task1 task1.cpp)

add_custom_target(run
COMMAND task1
DEPENDS task1
WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)