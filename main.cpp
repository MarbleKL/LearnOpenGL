#include <iostream>
#include "ZRender.h"

int main() {
    try {
        ZRender::Instance().Init();
        while (ZRender::Instance().Update());
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
