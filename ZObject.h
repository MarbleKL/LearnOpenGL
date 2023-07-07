//
// Created by zhujinan on 7/7/2023.
//

#ifndef LEARNOPENGL_ZOBJECT_H
#define LEARNOPENGL_ZOBJECT_H

#include <vector>
#include "ZBuffer.h"

class ZObject {
public:
    virtual void Init(float scale = 1, bool colourful = true, bool texture = false);

    void Update();

    void Stop();

protected:
    void generatePoint(const double directions[3], double scale, double textureCoords[2] = nullptr);

    virtual void InitVertices() {};

    virtual void InitIndices() {};

protected:
    unsigned int VBO{};
    unsigned int VAO{};
    unsigned int EBO{};

    ZBuffer<double> vertices{};
    ZBuffer<unsigned int> indices{};

    bool colourful_ = true;
    bool texture_ = false;

    double scale_{};
};


#endif //LEARNOPENGL_ZOBJECT_H
