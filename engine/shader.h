//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_SHADER_H
#define GAMEENGINE_SHADER_H

#include "../deps/glad/glad.h" // include glad to get all the required OpenGL headers
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

struct shaderArgs{
    int layoutLocationVertex;
    int layoutLocationColor;
    int layoutLocationTex;
    int layoutLocationNormals;
};


class Shader
{
private:
    void checkCompileErrors(unsigned int shader, std::string type);
public:
    // the program ID
    unsigned int ID;

    int layoutLocationVertex;
    int layoutLocationColor;
    int layoutLocationTex;
    int layoutLocationNormals;

    // constructor reads and builds the shader
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath, shaderArgs sa);
    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void set3f(const std::string &name, float x, float y, float z) const;
    void set3f(const std::string &name, const glm::vec3 &vec) const ;
    void setMatrix4fv(const std::string &name, glm::mat4 trans);
    void set4f(const std::string &name, float R, float G, float B, float O);
};

#endif //GAMEENGINE_SHADER_H
