cmake_minimum_required(VERSION 3.16)
project(OpenGL)

set(CMAKE_CXX_STANDARD 14)

set(MY_LIBS GLEW glfw GL)

add_compile_definitions(GLEW_STATIC)

add_executable(OpenGL src/main.cpp src/Window.h src/Shader.h)

target_link_libraries(OpenGL ${MY_LIBS})