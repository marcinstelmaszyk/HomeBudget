cmake_minimum_required(VERSION 3.17)
project(HomeBudget)

set(CMAKE_CXX_STANDARD 17)

include_directories(handlers)

add_subdirectory(handlers)

add_executable(HomeBudget main.cpp)

target_link_libraries(HomeBudget handlers)

