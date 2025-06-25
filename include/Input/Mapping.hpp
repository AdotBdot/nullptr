#pragma once

#include "InputEnums.hpp"

#include <tuple>

namespace Input
{
    struct Mapping
    {
        int Button;
        int Modifiers;
        int Action;

        Mapping(const int &key, const int &modifiers = 0, 
                const int &action = static_cast<int>(KeyEvent::Press));
        Mapping(const Key &key, const int &modifiers = 0,
                const KeyEvent &action = KeyEvent::Press);
    };

    //HACK: std::tie is not welcome here
    inline bool operator<(const Mapping &l, const Mapping &r)
    {
        return std::tie(l.Button, l.Modifiers, l.Action) < std::tie(r.Button, r.Modifiers, r.Action);
    }
}