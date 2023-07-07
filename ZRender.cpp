//
// Created by zhao4 on 2023/6/15.
//

#include "ZRender.h"

void ZRender::Init(bool lineMode, int scr_width, int scr_height) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(scr_width, scr_height, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) throw std::exception("Failed to create GLFW window");

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) throw std::exception("Failed to initialize GLAD");

    shaderProgram.Init();

    bufferManager.Init(lineMode);
}

bool ZRender::Update() {
    if (glfwWindowShouldClose(window)) {
        Stop();
        return false;
    }

    processInput();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shaderProgram.Update();
    bufferManager.Update();

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
    return true;
}


void ZRender::Stop() {
    shaderProgram.Stop();
    bufferManager.Stop();
    glfwTerminate();
}

void ZRender::processInput() {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

