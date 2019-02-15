cmake_minimum_required(VERSION 2.8)

project(task2)

include_directories( ${MY_SOURCE_DIR}/source )

add_executable(task2 source/task2.cpp)

add_custom_target(run
COMMAND task2
DEPENDS task2
WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)