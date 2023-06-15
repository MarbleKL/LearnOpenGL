//
// Created by zhao4 on 2023/6/15.
//

#include "ZShader.h"
#include <fstream>
#include <format>
#include <utility>
#include <glad/glad.h>

ZShader::ShaderId ZShader::GetId() const {
    return id_;
}

void ZShader::Init(std::string path, ShaderType type) {
    shaderPath_ = std::move(path);
    shaderType_ = type;
    state_ = Unloaded;
}

void ZShader::Load() {
    if (state_ != Unloaded)
        return;

    std::ifstream fin;
    fin.open(shaderPath_);
    if (!fin.is_open()) {
        message_ = std::format("Failed to open file: {}", shaderPath_);
        state_ = Failed;
        return;
    }

    shaderSource_.append((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());

    state_ = NotCompiled;
    fin.close();
}

void ZShader::Compile() {
    if (state_ != NotCompiled)
        return;

    id_ = glCreateShader(GetShaderType());
    const char *address = shaderSource_.c_str();
    glShaderSource(id_, 1, &address, nullptr);
    glCompileShader(id_);

    int success;
    glGetShaderiv(id_, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info[512];
        glGetShaderInfoLog(id_, 512, nullptr, info);
        message_.append(info);
        state_ = Failed;
        return;
    }

    state_ = Compiled;
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


