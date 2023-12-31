//
// Created by zhao4 on 2023/6/15.
//

#ifndef LEARNOPENGL_ZSHADERPROGRAM_H
#define LEARNOPENGL_ZSHADERPROGRAM_H


#include "ZShader.h"
#include <list>

class ZShaderProgram {
public:
    typedef unsigned int ShaderProgramId;

    void Init();

    void Update();

    void Stop();

private:
    const char *SHADER_PATH = "../Shader";
    std::list<ZShader> shaderList_[ZShader::ShaderTypeLength];
    ShaderProgramId id_;

private:

    void Link();

    void Use() const;
};


#endif //LEARNOPENGL_ZSHADERPROGRAM_H
