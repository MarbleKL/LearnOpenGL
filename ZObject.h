//
// Created by zhujinan on 7/7/2023.
//

#ifndef LEARNOPENGL_ZOBJECT_H
#define LEARNOPENGL_ZOBJECT_H

#include <vector>
#include <string>
#include "ZBuffer.h"
#include "ZTexture.h"

class ZObject {
public:
    typedef unsigned int VertexBufferId;
    typedef unsigned int VertexArrayId;
    typedef unsigned int ElementBufferId;

    virtual void Init(float scale, bool colourful, bool texture, std::string path);

    void Update();

    void Stop();

protected:
    void generatePoint(const double directions[3], double scale, double textureCoords[2] = nullptr);

    virtual void InitVertices() {};

    virtual void InitIndices() {};

protected:
    VertexBufferId vertexBufferId_{};
    VertexArrayId vertexArrayId_{};
    ElementBufferId elementBufferId_{};

    ZBuffer<double> vertices_{};
    ZBuffer<unsigned int> indices_{};
    ZTexture texture_;

    bool colourful_ = true;
    bool useTexture_ = false;

    double scale_{};
};


#endif //LEARNOPENGL_ZOBJECT_H
