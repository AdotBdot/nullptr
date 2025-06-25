#include "Input/MouseHandler.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace Input
{
    MouseHandler::MouseHandler()
    {
    }

    MouseHandler::~MouseHandler()
    {
    }

    void MouseHandler::setMouseMode(GLFWwindow *window, const MouseMode &mouseMode)
    {
        switch (mouseMode)
        {
        case MouseMode::Normal:
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            break;
        case MouseMode::Hidden:
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
            break;
        case MouseMode::Disabled:
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            break;
        default:
            break;
        }
    }

    void MouseHandler::setRawMouseInput(GLFWwindow *window, const bool &rawMouseInput)
    {
        if( !glfwRawMouseMotionSupported())
        {
            return;
        }

        glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, rawMouseInput ? GLFW_TRUE: GLFW_FALSE);
    }

    void MouseHandler::setStickyMouseButtons(GLFWwindow *window, const bool &stickyMouseButtons)
    {
        glfwSetInputMode(window, GLFW_CURSOR, stickyMouseButtons ? GLFW_TRUE: GLFW_FALSE);
    }

    glm::dvec2 MouseHandler::getMousePos(GLFWwindow *window) const
    {
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);

        return glm::dvec2(xPos, yPos);
    }

    void MouseHandler::bind(Mapping mapping, std::function<void()> function)
    {
        Mappings_[mapping] = function;
    }

    void MouseHandler::processKeyInput(const Mapping &input)
    {
        if(!Mappings_.contains(input))
            return;

        Mappings_[input]();
    }
}

