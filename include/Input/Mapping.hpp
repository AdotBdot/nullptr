#pragma once

#include "InputEnums.hpp"

#include <tuple>

namespace Input
{
    struct Mapping
    {
        int Key;
        int Modifiers;
        int Action;

        Mapping(const int key, const int modifiers = 0, const int action = KeyEvent::Press);
    };

    inline bool operator<(const Mapping &l, const Mapping &r)
    {
        return std::tie(l.Key, l.Modifiers, l.Action) < std::tie(r.Key, r.Modifiers, r.Action);
    }
}