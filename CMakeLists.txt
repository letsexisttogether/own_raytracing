cmake_minimum_required (VERSION 3.18)
project (RayTrace)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} Main.cpp)

add_subdirectory(Tools) 
add_subdirectory(ImageProcessors) 

target_link_libraries(${PROJECT_NAME} PRIVATE Tools)
