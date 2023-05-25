cmake_minimum_required (VERSION 3.18)
project (RayTrace)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} Main.cpp)

add_subdirectory(ImageProcessors) 
add_subdirectory(Tools) 
add_subdirectory(Fabrics)

target_link_libraries(${PROJECT_NAME} PRIVATE Tools)
target_link_libraries(${PROJECT_NAME} PRIVATE Fabrics)

add_custom_target(BuildAll DEPENDS ${PROJECT_NAME} ImageProcessors)
