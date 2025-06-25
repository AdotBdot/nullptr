#include "Input/Mapping.hpp"

#include <tuple>

namespace Input
{
    Mapping::Mapping(const int key, const int modifiers, const int action):
        Key(key),
        Modifiers(modifiers),
        Action(action)
    {
    }
}