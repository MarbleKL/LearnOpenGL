//
// Created by zhao4 on 2023/6/15.
//

#ifndef LEARNOPENGL_ZRENDER_H
#define LEARNOPENGL_ZRENDER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "ZStateful.h"
#include "ZShaderProgram.h"
#include "ZBufferManager.h"


class ZRender : public ZStateful {
public:
    enum State {
        Uninitialized = 0,
        Running,
        Stopped,
        Failed,
    };

    static ZRender &Instance() {
        static ZRender instance;
        return instance;
    }

    void Init(bool lineMode = false);

    void Update();

    void Stop();


private:
    void processInput();

private:
    const int SCR_WIDTH = 800;
    const int SCR_HEIGHT = 600;
    GLFWwindow *window{};
    ZShaderProgram shaderProgram;
    ZBufferManager bufferManager;
};


#endif //LEARNOPENGL_ZRENDER_H
