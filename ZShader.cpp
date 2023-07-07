//
// Created by zhao4 on 2023/6/15.
//

#include "ZShader.h"
#include <fstream>
#include <format>
#include <glad/glad.h>

ZShader::ShaderId ZShader::GetId() const {
    return id_;
}

void ZShader::Init(std::string path, ShaderType type) {
    shaderPath_ = std::move(path);
    shaderType_ = type;
}

void ZShader::Load() {
    std::ifstream fin;
    fin.open(shaderPath_);
    if (!fin.is_open()) {
        throw std::exception(std::format("Failed to open file: {}", shaderPath_).c_str());
    }

    shaderSource_.append((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
    fin.close();
}

void ZShader::Compile() {
    id_ = glCreateShader(GetShaderType());
    const char *address = shaderSource_.c_str();
    glShaderSource(id_, 1, &address, nullptr);
    glCompileShader(id_);

    int success;
    glGetShaderiv(id_, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info[512];
        glGetShaderInfoLog(id_, 512, nullptr, info);
        throw std::exception(info);
        return;
    }
}

unsigned int ZShader::GetShaderType() {
    switch (shaderType_) {
        case Vertex:
            return GL_VERTEX_SHADER;
        case Fragment:
            return GL_FRAGMENT_SHADER;
    }
    return 0;
}


