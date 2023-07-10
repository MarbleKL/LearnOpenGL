//
// Created by zhujinan on 7/7/2023.
//

#include "ZObject.h"
#include <glad/glad.h>
#include <exception>
#include <utility>

void ZObject::Init(float scale, bool colourful, bool texture, std::string path) {
    colourful_ = colourful;
    useTexture_ = texture;
    scale_ = scale;

    InitVertices();
    int verticesLength = vertices_.GetLength();
    if (verticesLength == 0) throw std::exception("vertices_ is empty");

    int unitLength = 3;
    if (colourful_) unitLength += 3;
    if (useTexture_) unitLength += 2;
    if (verticesLength % unitLength != 0) throw std::exception("vertices_ length is error");

    InitIndices();
    int indicesLength = indices_.GetLength();
    if (indicesLength == 0) throw std::exception("indices_ is empty");

    glGenVertexArrays(1, &vertexArrayId_);
    glGenBuffers(1, &vertexBufferId_);
    glGenBuffers(1, &elementBufferId_);

    glBindVertexArray(vertexArrayId_);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId_);
    glBufferData(GL_ARRAY_BUFFER, vertices_.GetSize(), vertices_.GetBuffer(),
                 GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferId_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_.GetSize(), indices_.GetBuffer(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, unitLength * (int) sizeof(double), nullptr);
    glEnableVertexAttribArray(0);
    if (colourful_) {
        glVertexAttribPointer(1, 3, GL_DOUBLE, GL_FALSE, unitLength * (int) sizeof(double),
                              (void *) (3 * sizeof(double)));
        glEnableVertexAttribArray(1);
    }
    if (useTexture_) {
        texture_.Init(std::move(path));
        texture_.Load();
        texture_.Generate();
        glVertexAttribPointer(2, 2, GL_DOUBLE, GL_FALSE, unitLength * (int) sizeof(double),
                              (void *) (6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }
}

void ZObject::Update() {
    if(useTexture_) glBindTexture(GL_TEXTURE_2D, texture_.GetId());
    glBindVertexArray(vertexArrayId_);
    glDrawElements(GL_TRIANGLES, indices_.GetLength(), GL_UNSIGNED_INT, nullptr);
}

void ZObject::Stop() {
    glDeleteVertexArrays(1, &vertexArrayId_);
    glDeleteBuffers(1, &vertexBufferId_);
    glDeleteBuffers(1, &elementBufferId_);
}

void ZObject::generatePoint(const double directions[3], double scale, double textureCoords[2]) {
    for (int i = 0; i < 3; i++) {
        vertices_.PushBack(directions[i] * scale);
    }

    if (colourful_) {
        for (int i = 0; i < 3; i++) {
            vertices_.PushBack(directions[i] * scale + 0.5);
        }
    }

    if (useTexture_) {
        if (textureCoords == nullptr) throw std::exception("textireCoords is nullptr");
        for (int i = 0; i < 2; i++) {
            vertices_.PushBack(textureCoords[i]);
        }
    }
}
