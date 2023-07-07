//
// Created by zhujinan on 6/25/2023.
//

#ifndef LEARNOPENGL_ZBUFFERMANAGER_H
#define LEARNOPENGL_ZBUFFERMANAGER_H

#include <list>
#include "ZBuffer.h"
#include "ZObject.h"

class ZBufferManager {
public:

    void Init(bool lineMode = false);

    void Update();

    void Stop();


private:
    std::list<ZObject*> objectList_;
};


#endif //LEARNOPENGL_ZBUFFERMANAGER_H
