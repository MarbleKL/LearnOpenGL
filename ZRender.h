//
// Created by zhao4 on 2023/6/15.
//

#ifndef LEARNOPENGL_ZRENDER_H
#define LEARNOPENGL_ZRENDER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "ZShaderProgram.h"
#include "ZBufferManager.h"


class ZRender {
public:
    static ZRender &Instance() {
        static ZRender instance;
        return instance;
    }

    void Init(bool lineMode = false, int scr_width = 800, int scr_height = 600);

    bool Update();

    void Stop();


private:
    void processInput();

private:
    GLFWwindow *window{};
    ZShaderProgram shaderProgram;
    ZBufferManager bufferManager;
};


#endif //LEARNOPENGL_ZRENDER_H
