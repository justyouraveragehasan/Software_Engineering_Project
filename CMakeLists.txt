cmake_minimum_required(VERSION 3.26)
project(Software_Engineering_Project)

set(CMAKE_CXX_STANDARD 17)

# Find SDL2 package using the sdl2-config or SDL2Config.cmake
find_package(SDL2 REQUIRED)

# Include SDL2 headers
include_directories(${SDL2_INCLUDE_DIRS})

# Add the executable for your project
add_executable(Software_Engineering_Project main.cpp)

# Link the SDL2 library to your project
target_link_libraries(Software_Engineering_Project ${SDL2_LIBRARIES})
