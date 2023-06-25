//
// Created by zhujinan on 6/25/2023.
//

#include "ZBufferManager.h"
#include <glad/glad.h>

void ZBufferManager::Init(bool lineMode) {
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

    if (lineMode) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
}

void ZBufferManager::Update() {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.GetLength(), GL_UNSIGNED_INT, nullptr);

}

void ZBufferManager::Stop() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
