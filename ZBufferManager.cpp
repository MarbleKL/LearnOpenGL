//
// Created by zhujinan on 6/25/2023.
//

#include "ZBufferManager.h"
#include "ZRectangle.h"
#include <glad/glad.h>

void ZBufferManager::Init(bool lineMode) {
    objectList_.push_back(new ZRectangle());
    for (ZObject *obj: objectList_) {
        obj->Init(0.5, true);
    }

    if (lineMode) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
}

void ZBufferManager::Update() {
    for (ZObject *obj: objectList_) {
        obj->Update();
    }
}

void ZBufferManager::Stop() {
    for (ZObject *obj: objectList_) {
        obj->Stop();
        delete obj;
    }
}
