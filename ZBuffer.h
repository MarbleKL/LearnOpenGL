//
// Created by zhujinan on 6/19/2023.
//

#ifndef LEARNOPENGL_ZBUFFER_H
#define LEARNOPENGL_ZBUFFER_H

template<class T>
class ZBuffer {
public:
    [[nodiscard]] T *GetBuffer() const;

    [[nodiscard]] unsigned int GetSize() const;

    void SetBuffer(T *buf, unsigned int len);

    ~ZBuffer();

private:
    T *buffer_;
    unsigned int length_;

};

template<class T>
ZBuffer<T>::~ZBuffer() {
    delete buffer_;
}

template<class T>
unsigned int ZBuffer<T>::GetSize() const {
    return sizeof(T) * length_;
}

template<class T>
T *ZBuffer<T>::GetBuffer() const {
    return buffer_;
}


template<class T>
void ZBuffer<T>::SetBuffer(T *buf, unsigned int len) {
    buffer_ = buf;
    length_ = len;
}


#endif //LEARNOPENGL_ZBUFFER_H
