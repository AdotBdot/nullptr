#pragma once

#include "glm/ext/vector_uint2.hpp"
#include <GLFW/glfw3.h>
#include <string>
#include <glm/vec2.hpp>

class Window{
    public:
    Window();
    Window(const std::string& title,const int width, const int height);
    Window(const std::string& title,const glm::uvec2& size);
    ~Window();

    void create(const std::string& title,const glm::uvec2& size);
    void close();
    void clear();
    void display();

    void setSize(const glm::uvec2& size);
    glm::uvec2 getSize()const;
    
    void setTitle(const std::string& title);
    std::string getTitle()const;

    GLFWwindow* getWindow();

    bool isRunning()const;

    
    private:
    GLFWwindow* window_;
    std::string title_;
    glm::uvec2 size_;
    
};