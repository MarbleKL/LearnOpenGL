//
// Created by zhujinan on 7/10/2023.
//

#ifndef LEARNOPENGL_ZTEXTURE_H
#define LEARNOPENGL_ZTEXTURE_H


#include <string>

class ZTexture {
public:
    typedef unsigned char TexData;
    typedef unsigned int TextureId;

    [[nodiscard]] TextureId GetId() const;

    void Init(std::string path);

    void Load();

    void Generate();

private:
    std::string texPath_;
    TextureId Id_;
    TexData *texData_;
    int width_;
    int height_;
    int channels_;

};


#endif //LEARNOPENGL_ZTEXTURE_H
