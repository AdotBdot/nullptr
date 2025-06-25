#include "Input/KeyboardHandler.hpp"

namespace Input
{
    KeyboardHandler::KeyboardHandler()
    {
    }

    KeyboardHandler::~KeyboardHandler()
    {
    }

    void KeyboardHandler::bind(Mapping mapping, std::function<void()> function)
    {
        Mappings_[mapping] = function;
    }

    void KeyboardHandler::processInput(const Mapping &input)
    {
        if(!Mappings_.contains(input))
            return;

        Mappings_[input]();
    }
}