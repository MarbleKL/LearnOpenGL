//
// Created by zhao4 on 2023/6/15.
//

#include "ZShaderProgram.h"
#include <filesystem>
#include <glad/glad.h>

void ZShaderProgram::Init() {
    for (const auto &entry: std::filesystem::directory_iterator(SHADER_PATH)) {
        std::string path = entry.path().generic_string();

        ZShader::ShaderType shaderType = ZShader::Vertex;

        if (entry.path().extension().compare(".vsh") == 0) {
            shaderType = ZShader::Vertex;
        } else if (entry.path().extension().compare(".fsh") == 0) {
            shaderType = ZShader::Fragment;
        }

        ZShader shader;
        shader.Init(path, shaderType);
        shader.Load();
        shader.Compile();

        if (shader.GetState() == ZShader::Failed) {
            message_ = shader.GetMessage();
            state_ = Failed;
            return;
        }

        shaderList_[shaderType].push_back(std::move(shader));
    }
    state_ = NotLinked;
    Link();
}

void ZShaderProgram::Link() {
    id_ = glCreateProgram();
    for (const auto &shader: shaderList_[ZShader::Vertex]) {
        glAttachShader(id_, shader.GetId());
    }
    for (const auto &shader: shaderList_[ZShader::Fragment]) {
        glAttachShader(id_, shader.GetId());
    }
    glLinkProgram(id_);
    for (const auto &shader: shaderList_[ZShader::Vertex]) {
        glDeleteShader(shader.GetId());
    }
    for (const auto &shader: shaderList_[ZShader::Fragment]) {
        glDeleteShader(shader.GetId());
    }

    int success;
    glGetProgramiv(id_, GL_LINK_STATUS, &success);
    if (!success) {
        char info[512];
        glGetProgramInfoLog(id_, 512, nullptr, info);
        message_.append(info);
        state_ = Failed;
        return;
    }
    state_ = NotUsed;
}

void ZShaderProgram::Use() const {
    glUseProgram(id_);
}

void ZShaderProgram::Stop() {
    glDeleteProgram(id_);
}

void ZShaderProgram::Update() {
    Use();
}
