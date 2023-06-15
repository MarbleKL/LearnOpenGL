#include <iostream>
#include "ZRender.h"

int main() {
    ZRender::Instance().Init();
    if (ZRender::Instance().GetState() == ZRender::Failed) {
        std::cout << ZRender::Instance().GetMessage() << std::endl;
    }

    while (ZRender::Instance().GetState() == ZRender::Running) {
        ZRender::Instance().Update();
    }

    return 0;
}
