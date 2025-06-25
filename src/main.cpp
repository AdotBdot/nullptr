#include "Input/KeyboardHandler.hpp"
#include "Input/CallbackHandler.hpp"
#include "Window.hpp"
#include "Shader.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <print>

static void error_callback(int error, const char *description) {
  fputs(description, stderr);
}

int main(void) {
  Window window("Simple example", 800, 600);
  glfwSetErrorCallback(error_callback);

  if (!gladLoadGL(glfwGetProcAddress)) {
    std::print("Failed to initialize glad");
    return -1;
  }

  // Input
  Input::KeyboardHandler keyboardHandler;
  Input::CallbackHandler::setActiveKeyboardHandler(keyboardHandler);
  glfwSetKeyCallback(window.getWindow(), Input::CallbackHandler::KeyCallback);

  keyboardHandler.bind(Input::Mapping(Input::Key::Escape), [&](void) { window.close(); });

  // Triangle
  float vertices[] = {
         0.0f,  0.5f, 0.0f, 
        -0.5f, -0.5f, 0.0f, 
         1.0f, -0.5f, 0.0f  
    };

  unsigned int VAO, VBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Shaders
  Shader *vertexShader = Shader::loadFromFile("../resources/triangle_vert.glsl", ShaderType::Vertex);
  Shader *fragmentShader = Shader::loadFromFile("../resources/triangle_frag.glsl", ShaderType::Fragment);

  vertexShader->compile();
  fragmentShader->compile();

  ShaderProgram shaderProgram({vertexShader, fragmentShader});

  delete vertexShader;
  delete fragmentShader;

  while (window.isRunning()) {
    int width, height;
    glfwGetFramebufferSize(window.getWindow(), &width, &height);
    glViewport(0, 0, width, height);

    float time = static_cast<float>(glfwGetTime());
    glm::mat4 transform = glm::rotate(glm::mat4(1.0f), time, glm::vec3(0.0f, 0.0f, 1.0f));
    shaderProgram.setMat("transform", transform);

    window.clear();

    shaderProgram.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    window.display();

    glfwPollEvents();
  }
}
