//
// Created by zhujinan on 6/25/2023.
//

#ifndef LEARNOPENGL_ZBUFFERMANAGER_H
#define LEARNOPENGL_ZBUFFERMANAGER_H

#include "ZBuffer.h"

class ZBufferManager {
public:

    void Init(bool lineMode = false);

    void Update();

    void Stop();


private:
    unsigned int VBO{};
    unsigned int VAO{};
    unsigned int EBO{};

    ZBuffer<float> vertices{};
    ZBuffer<unsigned int> indices{};
};


#endif //LEARNOPENGL_ZBUFFERMANAGER_H
