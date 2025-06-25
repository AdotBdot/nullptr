#pragma once

#include "Mapping.hpp"

#include <functional>
#include <map>

namespace Input
{
    class KeyboardHandler
    {
    private:
        std::map<Mapping, std::function<void()>> Mappings_;

    public:
        KeyboardHandler();
        ~KeyboardHandler();

        void bind(Mapping mapping, std::function<void()> function);
        void processInput(const Mapping &input);
    };
}