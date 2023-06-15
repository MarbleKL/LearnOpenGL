//
// Created by zhao4 on 2023/6/15.
//

#ifndef LEARNOPENGL_ZSTATEFUL_H
#define LEARNOPENGL_ZSTATEFUL_H

#include <string>

class ZStateful {
public:
    typedef int State;

    [[nodiscard]] State GetState() const {
        return state_;
    }


    [[nodiscard]] std::string GetMessage() const {
        return message_;
    }

protected:
    State state_ = 0;
    std::string message_;

};


#endif //LEARNOPENGL_ZSTATEFUL_H
