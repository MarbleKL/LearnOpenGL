//
// Created by zhujinan on 7/7/2023.
//

#include "ZRectangle.h"

void ZRectangle::InitVertices() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            double temp[3]{static_cast<double>(1 + i * -2), static_cast<double>(1 + j * -2), 0};
            generatePoint(temp, scale_);
        }
    }
}

void ZRectangle::InitIndices() {
    int temp[6]{0, 1, 2, 3, 1, 2};
    for (int i : temp) {
        indices.PushBack(i);
    }
}
