//
// Created by zhujinan on 7/7/2023.
//

#ifndef LEARNOPENGL_ZRECTANGLE_H
#define LEARNOPENGL_ZRECTANGLE_H


#include "ZObject.h"

class ZRectangle : public ZObject {
public:

protected:
    void InitVertices() override;

    void InitIndices() override;
};


#endif //LEARNOPENGL_ZRECTANGLE_H
