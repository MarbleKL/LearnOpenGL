//
// Created by zhao4 on 2023/6/15.
//

#include "ZRender.h"

void ZRender::Init(bool lineMode) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        message_ = "Failed to create GLFW window";
        state_ = Failed;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        message_ = "Failed to initialize GLAD";
        state_ = Failed;
        return;
    }

    shaderProgram.Init();

    if (shaderProgram.GetState() == ZShaderProgram::Failed) {
        message_ = shaderProgram.GetMessage();
        state_ = Failed;
        return;
    }

    bufferManager.Init(lineMode);

    state_ = Running;
}

void ZRender::Update() {
    if (state_ != Running)
        return;

    if (glfwWindowShouldClose(window))
        Stop();

    processInput();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    shaderProgram.Update();
    bufferManager.Update();

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
}


void ZRender::Stop() {
    state_ = Stopped;
    shaderProgram.Stop();
    bufferManager.Stop();
    glfwTerminate();
}

void ZRender::processInput() {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

