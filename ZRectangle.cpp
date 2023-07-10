//
// Created by zhujinan on 7/7/2023.
//

#include "ZRectangle.h"

void ZRectangle::InitVertices() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            double dir[3]{(double) (1 + i * -2), (double) (1 + j * -2), 0};
            double tex[2]{(double) (i), (double) (j)};
            generatePoint(dir, scale_,tex);
        }
    }
}

void ZRectangle::InitIndices() {
    int temp[6]{0, 1, 2, 3, 1, 2};
    for (int i: temp) {
        indices_.PushBack(i);
    }
}
