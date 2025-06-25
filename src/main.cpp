#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "Input/KeyboardHandler.hpp"
#include "Input/CallbackHandler.hpp"
#include "Window.hpp"

static void error_callback(int error, const char *description) {
  fputs(description, stderr);
}

void drawTriangle(float ratio) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
  glBegin(GL_TRIANGLES);
  glColor3f(1.f, 0.f, 0.f);
  glVertex3f(-0.6f, -0.4f, 0.f);
  glColor3f(0.f, 1.f, 0.f);
  glVertex3f(0.6f, -0.4f, 0.f);
  glColor3f(0.f, 0.f, 1.f);
  glVertex3f(0.f, 0.6f, 0.f);
  glEnd();
}

int main(void) {
  Window window("Simple example", 800, 600);
  glfwSetErrorCallback(error_callback);
  // Input
  Input::KeyboardHandler keyboardHandler;
  Input::CallbackHandler::setActiveKeyboardHandler(keyboardHandler);
  glfwSetKeyCallback(window.getWindow(), Input::CallbackHandler::KeyCallback);

  keyboardHandler.bind(Input::Mapping(Input::Key::Escape),
                    [&](void) { window.close(); });

  while (window.isRunning()) {
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window.getWindow(), &width, &height);
    ratio = width / (float)height;
    glViewport(0, 0, width, height);

    window.clear();
    drawTriangle(ratio);
    window.display();

    glfwPollEvents();
  }
}
