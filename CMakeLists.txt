cmake_minimum_required(VERSION 3.14)
project(bloom_and_boggle LANGUAGES CXX)

include_directories(include)
add_library(bloom src/Bloom.cpp)
target_include_directories(bloom PUBLIC include)

enable_testing()
add_subdirectory(tests)
