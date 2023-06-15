//
// Created by zhao4 on 2023/6/15.
//

#include "ZShaderProgram.h"
#include <filesystem>

void ZShaderProgram::Init() {
    for (const auto &entry: std::filesystem::directory_iterator(SHADER_PATH)) {
        std::string path = entry.path().generic_string();

        ZShader::ShaderType shaderType;

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
}
