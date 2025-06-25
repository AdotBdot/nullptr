#include "Input/Mapping.hpp"

#include <tuple>

namespace Input
{
    Mapping::Mapping(const int &key, const int &modifiers, const int &action):
        Button(key),
        Modifiers(modifiers),
        Action(action)
    {
    }

    Mapping::Mapping(const Key &key, const int &modifiers, const KeyEvent &action):
        Button(static_cast<int>(key)),
        Modifiers(modifiers),
        Action(static_cast<int>(action))
    {
    }
}


