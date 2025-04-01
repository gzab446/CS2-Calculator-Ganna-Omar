cmake_minimum_required(VERSION 3.10)

# Set project name
project(CS2_Calculator_Project)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
add_executable(calculator test.cpp calculator.cpp)
