cmake_minimum_required (VERSION 3.14)

project (DesignPatterns VERSION 0.0.1)

add_subdirectory("src")

target_include_directories(DesignPatterns PRIVATE include)

set_property(TARGET DesignPatterns PROPERTY CXX_STANDARD 23)
