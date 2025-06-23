#include "Shader.hpp"

#include <glad/gl.h>

#include <fstream>
#include <sstream>
#include <print>

//--Shader class --------------------------------------------------------------

Shader::Shader(const std::string &src, const GLsizei length, const ShaderType &type)
{
    id_ = glCreateShader(type);
    const char *c_str = src.c_str();
    glShaderSource(id_, 1, &c_str, &length);
}

Shader::~Shader()
{
    glDeleteShader(id_);
}

void Shader::compile()
{
    glCompileShader(id_);

    int success;
    glGetShaderiv(id_, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(id_, 512, NULL, infoLog);
        std::print("Shader [{0}] error: {1}", id_, infoLog);
    }
}

GLuint Shader::getId() const
{
    return id_;
}

//TODO: Check if file.good()
Shader *Shader::loadFromFile(const std::string shaderPath, const ShaderType type)
{
    std::ifstream file;
    file.open(shaderPath);

    std::stringstream buffer;
    buffer << file.rdbuf();
    GLsizei length = file.tellg();
    file.close();

    return new Shader(buffer.str().c_str(), length, type);
}

//--ShaderProgram class --------------------------------------------------------------
ShaderProgram::ShaderProgram(std::vector<Shader*> shaders)
{
    id_ = glCreateProgram();

    for(Shader* shader: shaders)
        glAttachShader(id_, shader->getId());

    glLinkProgram(id_);

    int success;
    glGetProgramiv(id_, GL_LINK_STATUS, &success);
    if(!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(id_, 512, NULL, infoLog);
        std::print("Shader program [{0}] error: {1}", id_, infoLog);
    }
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(id_);
}

void ShaderProgram::use()
{
    glUseProgram(id_);
}

GLuint ShaderProgram::getId() const
{
    return id_;
}

void ShaderProgram::setBool(const std::string &name, const bool &value) const
{
    glUniform1i(glGetUniformLocation(id_, name.c_str()), static_cast<int>(value));
}

void ShaderProgram::setInt(const std::string &name, const int &value) const
{
    glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
}

void ShaderProgram::setFloat(const std::string &name, const float &value) const
{
    glUniform1f(glGetUniformLocation(id_, name.c_str()), value);
}

void ShaderProgram::setVec(const std::string &name, const glm::vec2 &value) const
{
    glUniform2fv(glGetUniformLocation(id_, name.c_str()), 1, &value[0]);
}

void ShaderProgram::setVec(const std::string &name, const glm::vec3 &value) const
{
    glUniform3fv(glGetUniformLocation(id_, name.c_str()), 1, &value[0]);
}

void ShaderProgram::setVec(const std::string &name, const glm::vec4 &value) const
{
    glUniform4fv(glGetUniformLocation(id_, name.c_str()), 1, &value[0]);
}

void ShaderProgram::setMat(const std::string &name, const glm::mat2 &value) const
{
    glUniformMatrix2fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void ShaderProgram::setMat(const std::string &name, const glm::mat3 &value) const
{
    glUniformMatrix3fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void ShaderProgram::setMat(const std::string &name, const glm::mat4 &value) const
{
    glUniformMatrix4fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE, &value[0][0]);
}
