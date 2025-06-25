#include "Input/CallbackHandler.hpp"
#include "CallbackHandler.hpp"

namespace Input
{
    KeyboardHandler* CallbackHandler::ActiveKeyboardHandler_{nullptr};
    MouseHandler* CallbackHandler::ActiveMouseHandler_{nullptr};

    void CallbackHandler::setActiveKeyboardHandler(KeyboardHandler &inputHandler)
    {
        ActiveKeyboardHandler_ = &inputHandler;
    }

    void CallbackHandler::setActiveMouseHandler(MouseHandler &mouseHandler)
    {
        ActiveMouseHandler_ = &mouseHandler;
    }

    void CallbackHandler::KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        Mapping input(key, mods, action);
        ActiveKeyboardHandler_->processInput(input);
    }

    void CallbackHandler::MouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
    {
        Mapping input(key, mods, action);
        ActiveMouseHandler_->processKeyInput(input);
    }

    void CallbackHandler::MousePosCallback(GLFWwindow *window, double xPos, double yPos)
    {
    }

    void CallbackHandler::ScrollCallback(GLFWwindow *window, double xOffset, double yOffset)
    {
    }
}