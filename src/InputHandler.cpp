#include "InputHandler.hpp"

#include <print>

namespace Input
{

InputHandler* CallbackHandler::ActiveInputHandler{nullptr};

Mapping::Mapping(const int key, const int modifiers):
    Key(key),
    Modifiers(modifiers)
{
}

bool Mapping::operator<(const Mapping &other) const
{
    return std::make_pair(Key, Modifiers) < std::make_pair(other.Key, other.Modifiers);
}

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

void CallbackHandler::setActiveInputHandler(InputHandler &inputHandler)
{
    ActiveInputHandler = &inputHandler;
}

void CallbackHandler::KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    Mapping input(key, mods);
    ActiveInputHandler->processInput(input);
}
}