//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_SHADER_H
#define GAMEENGINE_SHADER_H

#include "../deps/glad/glad.h" // include glad to get all the required OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader
{
private:
    void checkCompileErrors(unsigned int shader, std::string type);
public:
    // the program ID
    unsigned int ID;

    // constructor reads and builds the shader
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};

#endif //GAMEENGINE_SHADER_H
