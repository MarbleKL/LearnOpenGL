//
// Created by zhujinan on 7/7/2023.
//

#include "ZObject.h"
#include <glad/glad.h>
#include <exception>

void ZObject::Init(float scale, bool colourful, bool texture) {
    colourful_ = colourful;
    texture_ = texture;
    scale_ = scale;

    InitVertices();
    int verticesLength = vertices.GetLength();
    if (verticesLength == 0) throw std::exception("vertices is empty");

    int unitLength = 3;
    if (colourful_) unitLength += 3;
    if (texture_) unitLength += 2;
    if (verticesLength % unitLength != 0) throw std::exception("vertices length is error");

    InitIndices();
    int indicesLength = indices.GetLength();
    if (indicesLength == 0) throw std::exception("indices is empty");

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.GetSize(), vertices.GetBuffer(),
                 GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.GetSize(), indices.GetBuffer(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, unitLength * (int) sizeof(double), nullptr);
    glEnableVertexAttribArray(0);
    if (colourful_) {
        glVertexAttribPointer(1, 3, GL_DOUBLE, GL_FALSE, unitLength * (int) sizeof(double),
                              (void *) (3 * sizeof(double)));
        glEnableVertexAttribArray(1);
    }
    if (texture_) {
        glVertexAttribPointer(2, 2, GL_DOUBLE, GL_FALSE, unitLength * (int) sizeof(double),
                              (void *) (6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }
}

void ZObject::Update() {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.GetLength(), GL_UNSIGNED_INT, nullptr);
}

void ZObject::Stop() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void ZObject::generatePoint(const double directions[3], double scale, double textureCoords[2]) {
    for (int i = 0; i < 3; i++) {
        vertices.PushBack(directions[i] * scale);
    }

    if (colourful_) {
        for (int i = 0; i < 3; i++) {
            vertices.PushBack(directions[i] * scale + 0.5);
        }
    }

    if (texture_) {
        if (textureCoords == nullptr) {
            throw std::exception("textireCoords is nullptr");
        }
        for (int i = 0; i < 2; i++) {
            vertices.PushBack(textureCoords[i]);
        }
    }
}
