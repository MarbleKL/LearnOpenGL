//
// Created by zhao4 on 2023/6/15.
//

#include "ZRender.h"

void ZRender::Init() {
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
    shaderProgram.Link();

    if (shaderProgram.GetState() == ZShaderProgram::Failed) {
        message_ = shaderProgram.GetMessage();
        state_ = Failed;
        return;
    }

    vertices.SetBuffer(new float[]{0.5f, 0.5f, 0.0f,
                                   0.5f, -0.5f, 0.0f,
                                   -0.5f, -0.5f, 0.0f,
                                   -0.5f, 0.5f, 0.0f}, 12);
    indices.SetBuffer(new unsigned int[]{0, 1, 3,
                                         1, 2, 3}, 6);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.GetSize(), vertices.GetBuffer(),
                 GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.GetSize(), indices.GetBuffer(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

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


    shaderProgram.Use();
    glBindVertexArray(VAO);
//    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, indices.GetLength(), GL_UNSIGNED_INT, nullptr);

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
}


void ZRender::Stop() {
    state_ = Stopped;

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram.GetId());
    glfwTerminate();
}

void ZRender::processInput() {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

