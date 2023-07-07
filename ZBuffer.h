//
// Created by zhujinan on 6/19/2023.
//

#ifndef LEARNOPENGL_ZBUFFER_H
#define LEARNOPENGL_ZBUFFER_H

#include <vector>

template<class T>
class ZBuffer {
public:
    [[nodiscard]] T *GetBuffer();

    [[nodiscard]] int GetSize() const;

    [[nodiscard]] int GetLength() const;

    void PushBack(T element);

private:
    std::vector<T> buffer_;
};

template<class T>
int ZBuffer<T>::GetLength() const {
    return buffer_.size();
}

template<class T>
int ZBuffer<T>::GetSize() const {
    return sizeof(T) * buffer_.size();
}

template<class T>
T *ZBuffer<T>::GetBuffer() {
    return buffer_.data();
}


template<class T>
void ZBuffer<T>::PushBack(T element) {
    buffer_.push_back(element);
}


#endif //LEARNOPENGL_ZBUFFER_H
