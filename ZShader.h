//
// Created by zhao4 on 2023/6/15.
//

#ifndef LEARNOPENGL_ZSHADER_H
#define LEARNOPENGL_ZSHADER_H

#include <string>

class ZShader {
public:
    typedef unsigned int ShaderId;
    enum State {
        Uninitialized = 0,
        Unloaded,
        NotCompiled,
        Compiled,
        Failed,
    };

    enum ShaderType {
        Vertex = 0,
        Fragment,
    };
    static const int ShaderTypeLength = 2;

    [[nodiscard]] ShaderId GetId() const;

    void Init(std::string path, ShaderType type);

    void Load();

    void Compile();

private:
    unsigned int GetShaderType();

private:
    ShaderId id_;
    std::string shaderSource_;
    std::string shaderPath_;
    ShaderType shaderType_;

};


#endif //LEARNOPENGL_ZSHADER_H
