#include "../include/Window.hpp"
#include "GLFW/glfw3.h"
#include <GL/gl.h>

Window::Window() : window_(nullptr) {}

Window::Window(const std::string &title, const int width, const int height) {
  create(title, {width, height});
}

Window::Window(const std::string &title, const glm::uvec2 &size) {
  create(title, size);
}

Window::~Window() { 
  close(); 
  glfwDestroyWindow(window_);
  glfwTerminate();
}

void Window::create(const std::string &title, const glm::uvec2 &size) {
  // TODO Print Error when glfw did not initialize
  if (!glfwInit())
    return;

  window_ = glfwCreateWindow(size.x, size.y, title.c_str(), NULL, NULL);
  setSize(size);
  setTitle(title);

  // TODO Print Error when some error occured while creating window
  if (!window_) {
    close();
    return;
  }

  glfwMakeContextCurrent(window_);
}

void Window::close() {
  glfwSetWindowShouldClose(window_, true);
}

void Window::setTitle(const std::string &title) {
  title_ = title;
  glfwSetWindowTitle(window_, title_.c_str());
}

void Window::setSize(const glm::uvec2 &size) {
  size_ = size;
  glfwSetWindowSize(window_, size.x, size.y);
}
void Window::clear() { glClear(GL_COLOR_BUFFER_BIT); }

void Window::display() { 
  //HACK Temp fix for triangle not rendering
  glGetError();
  glfwSwapBuffers(window_); 
}

GLFWwindow *Window::getWindow() { return window_; };

bool Window::isRunning() const{
  return  ! glfwWindowShouldClose(window_);
}
