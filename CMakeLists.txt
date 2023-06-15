cmake_minimum_required(VERSION 3.25)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 20)

add_executable(LearnOpenGL main.cpp glad.c ZRender.cpp ZRender.h ZShader.cpp ZShader.h ZShaderProgram.cpp ZShaderProgram.h ZStateful.h)

include_directories("C:\\opengl\\glfw-3.3.8.bin.WIN64\\include")

target_link_libraries(LearnOpenGL "C:\\opengl\\glfw-3.3.8.bin.WIN64\\lib-vc2022\\glfw3.lib")