#pragma once

#include <glad/gl.h>
#include <glm/glm.hpp>

#include <string>
#include <vector>

enum ShaderType
{
    Vertex = GL_VERTEX_SHADER,
    TessControl = GL_TESS_CONTROL_SHADER,
    TessEvaluation = GL_TESS_EVALUATION_SHADER,
    Geometry = GL_GEOMETRY_SHADER,
    Fragment = GL_FRAGMENT_SHADER,
    Compute = GL_COMPUTE_SHADER
};

class Shader
{
private:
    GLuint id_;

public:
    Shader(const std::string &src, const GLsizei length, const ShaderType &type);
    ~Shader();

    void compile();
    GLuint getId() const;

    static Shader* loadFromFile(const std::string shaderPath, const ShaderType type);
};

class ShaderProgram
{
private:
    GLuint id_;

public:
    ShaderProgram(std::vector<Shader*> shaders);
    ~ShaderProgram();

    void use();
    GLuint getId() const;

    void setBool(const std::string &name, const bool &value) const;
    void setInt(const std::string &name, const int &value) const;
    void setFloat(const std::string &name, const float &value) const;
    void setVec(const std::string &name, const glm::vec2 &value) const;
    void setVec(const std::string &name, const glm::vec3 &value) const;
    void setVec(const std::string &name, const glm::vec4 &value) const;
    void setMat(const std::string &name, const glm::mat2 &value) const;
    void setMat(const std::string &name, const glm::mat3 &value) const;
    void setMat(const std::string &name, const glm::mat4 &value) const;
};