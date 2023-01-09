cmake_minimum_required(VERSION 3.0.0)
project(test-1 VERSION 0.1.0)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

link_libraries(${GLEW_LIBRARIES})


add_executable(test-1 main.cpp Window.cpp)

target_link_libraries(test-1 OpenGL::GL)
target_link_libraries(test-1 glfw)
