#include "Input.hpp"

#include <print>

namespace Input
{
//--Mapping--------------------------------------
Mapping::Mapping(const int key, const int modifiers, const int action):
    Key(key),
    Modifiers(modifiers),
    Action(action)
{
}

bool operator<(const Mapping &l, const Mapping &r)
{
    return std::tie(l.Key, l.Modifiers, l.Action) < std::tie(r.Key, r.Modifiers, r.Action);
}

//--CallbackHandler--------------------------------------
InputHandler* CallbackHandler::ActiveInputHandler{nullptr};

void CallbackHandler::setActiveInputHandler(InputHandler &inputHandler)
{
    ActiveInputHandler = &inputHandler;
}

void CallbackHandler::KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    Mapping input(key, mods, action);
    ActiveInputHandler->processInput(input);
}

//--InputHandler--------------------------------------
InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

void InputHandler::bind(Mapping mapping, std::function<void()> function)
{
    Mappings_[mapping] = function;
}

void InputHandler::processInput(const Mapping &input)
{
    if(!Mappings_.contains(input))
        return;

    Mappings_[input]();
}

}