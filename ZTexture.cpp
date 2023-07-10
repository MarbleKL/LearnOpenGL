//
// Created by zhujinan on 7/10/2023.
//

#include "ZTexture.h"
#include <utility>

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
#include <glad/glad.h>

void ZTexture::Init(std::string path) {
    texPath_ = std::move(path);
}

void ZTexture::Load() {
    texData_ = stbi_load(texPath_.c_str(), &width_, &height_, &channels_, 0);
}

void ZTexture::Generate() {
    if (texData_ == nullptr) throw std::exception("TexData is nullptr");
    glGenTextures(1, &Id_);
    glBindTexture(GL_TEXTURE_2D, Id_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width_, height_, 0, GL_RGB, GL_UNSIGNED_BYTE, texData_);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(texData_);
}

ZTexture::TextureId ZTexture::GetId() const {
    return Id_;
}
