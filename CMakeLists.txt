cmake_minimum_required(VERSION 3.25)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 20)

add_executable(LearnOpenGL
        main.cpp
        glad.c
        ZRender.cpp
        ZRender.h
        ZShader.cpp ZShader.h ZShaderProgram.cpp ZShaderProgram.h ZBuffer.h ZBufferManager.cpp ZBufferManager.h
        ZObject.cpp ZObject.h ZObject.h ZRectangle.cpp ZRectangle.h ZTexture.cpp ZTexture.h stb_image.h)

include_directories("./glfw/include")

target_link_libraries(LearnOpenGL "../glfw/lib-vc2022/glfw3")