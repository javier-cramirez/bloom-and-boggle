cmake_minimum_required(VERSION 3.14)
project(bloom_and_boggle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)
add_library(bloom src/Bloom.cpp)
target_include_directories(bloom PUBLIC include)

enable_testing()
add_subdirectory(tests)
