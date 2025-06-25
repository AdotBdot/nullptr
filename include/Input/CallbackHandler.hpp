#pragma once

#include "KeyboardHandler.hpp"
#include "MouseHandler.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace Input
{
    class CallbackHandler
    {
    private:
        static KeyboardHandler *ActiveKeyboardHandler_;
        static MouseHandler *ActiveMouseHandler_;

    public:
        static void setActiveKeyboardHandler(KeyboardHandler &inputHandler);
        static void setActiveMouseHandler(MouseHandler &mouseHandler);

        static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void MouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
        static void MousePosCallback(GLFWwindow *window, double xPos, double yPos);
        static void ScrollCallback(GLFWwindow *window, double xOffset, double yOffset);
    };
}