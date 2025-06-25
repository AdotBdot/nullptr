#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace Input
{
    
    enum KeyEvent
    {
        Press = GLFW_PRESS,
        Release = GLFW_RELEASE,
        Hold = GLFW_REPEAT
    };

    enum Modifier
    {
        Shift = GLFW_MOD_SHIFT,
        Control = GLFW_MOD_CONTROL,
        Alt = GLFW_MOD_ALT,
        Super = GLFW_MOD_SUPER,
        CapsLock = GLFW_MOD_CAPS_LOCK,
        NumLock = GLFW_MOD_NUM_LOCK
    };

    //TODO: Add F1-25 keys
    //TODO: fix CapsLock and NumLock redefinition
    enum Key
    {
        Space = GLFW_KEY_SPACE,
        Escape = GLFW_KEY_ESCAPE,
        Enter = GLFW_KEY_ENTER,
        Tab = GLFW_KEY_TAB,
        Backspace = GLFW_KEY_BACKSPACE,
        Insert = GLFW_KEY_INSERT,
        Delete = GLFW_KEY_DELETE,
        PageUp = GLFW_KEY_PAGE_UP,
        PageDown = GLFW_KEY_PAGE_DOWN,
        Home = GLFW_KEY_HOME,
        End = GLFW_KEY_END,
        //CapsLock = GLFW_KEY_CAPS_LOCK,
        ScrollLock = GLFW_KEY_SCROLL_LOCK,
        //NumLock = GLFW_KEY_NUM_LOCK,
        PrintScreen = GLFW_KEY_PRINT_SCREEN,
        Pause = GLFW_KEY_PAUSE,
        Left = GLFW_KEY_LEFT,
        Right = GLFW_KEY_RIGHT,
        Up = GLFW_KEY_UP,
        Down = GLFW_KEY_DOWN,
        LeftAlt = GLFW_KEY_LEFT_ALT,
        RightAlt = GLFW_KEY_RIGHT_ALT,
        LeftControl = GLFW_KEY_LEFT_CONTROL,
        RightControl = GLFW_KEY_RIGHT_CONTROL,
        LeftShift = GLFW_KEY_LEFT_SHIFT,
        RightShift = GLFW_KEY_RIGHT_SHIFT,
        LeftSuper = GLFW_KEY_LEFT_SUPER,
        RightSuper = GLFW_KEY_RIGHT_SUPER,
        Menu = GLFW_KEY_MENU,
        Apostrophe = GLFW_KEY_APOSTROPHE,
        Comma = GLFW_KEY_COMMA,
        Minus = GLFW_KEY_MINUS,
        Period = GLFW_KEY_PERIOD,
        Slash = GLFW_KEY_SLASH,
        Backslash = GLFW_KEY_BACKSLASH,
        Semicolon = GLFW_KEY_SEMICOLON,
        Equal = GLFW_KEY_EQUAL,
        LeftBracket = GLFW_KEY_LEFT_BRACKET,
        RightBracket = GLFW_KEY_RIGHT_BRACKET,
        Grave = GLFW_KEY_GRAVE_ACCENT,
        A = GLFW_KEY_A,
        B = GLFW_KEY_B,
        C = GLFW_KEY_C,
        D = GLFW_KEY_D,
        E = GLFW_KEY_E,
        F = GLFW_KEY_F,
        G = GLFW_KEY_G,
        H = GLFW_KEY_H,
        I = GLFW_KEY_I,
        J = GLFW_KEY_J,
        K = GLFW_KEY_K,
        L = GLFW_KEY_L,
        M = GLFW_KEY_M,
        N = GLFW_KEY_N,
        O = GLFW_KEY_O,
        P = GLFW_KEY_P,
        Q = GLFW_KEY_Q,
        R = GLFW_KEY_R,
        S = GLFW_KEY_S,
        T = GLFW_KEY_T,
        U = GLFW_KEY_U,
        V = GLFW_KEY_V,
        W = GLFW_KEY_W,
        X = GLFW_KEY_X,
        Y = GLFW_KEY_Y,
        Z = GLFW_KEY_Z,
        K_0 = GLFW_KEY_0,
        K_1 = GLFW_KEY_1,
        K_2 = GLFW_KEY_2,
        K_3 = GLFW_KEY_3,
        K_4 = GLFW_KEY_4,
        K_5 = GLFW_KEY_5,
        K_6 = GLFW_KEY_6,
        K_7 = GLFW_KEY_7,
        K_8 = GLFW_KEY_8,
        K_9 = GLFW_KEY_9,
        NP_0 = GLFW_KEY_KP_0,
        NP_1 = GLFW_KEY_KP_1,
        NP_2 = GLFW_KEY_KP_2,
        NP_3 = GLFW_KEY_KP_3,
        NP_4 = GLFW_KEY_KP_4,
        NP_5 = GLFW_KEY_KP_5,
        NP_6 = GLFW_KEY_KP_6,
        NP_7 = GLFW_KEY_KP_7,
        NP_8 = GLFW_KEY_KP_8,
        NP_9 = GLFW_KEY_KP_9,
        NP_Decimal = GLFW_KEY_KP_DECIMAL,
        NP_Divide = GLFW_KEY_KP_DIVIDE,
        NP_Multiply = GLFW_KEY_KP_MULTIPLY,
        NP_Subtract = GLFW_KEY_KP_SUBTRACT,
        NP_Add = GLFW_KEY_KP_ADD,
        NP_Enter = GLFW_KEY_KP_ENTER,
        NP_Equal = GLFW_KEY_KP_EQUAL
    };

    enum MouseKey
    {
        Left = GLFW_MOUSE_BUTTON_LEFT,
        Right = GLFW_MOUSE_BUTTON_RIGHT,
        Middle = GLFW_MOUSE_MIDDLE,
        Last = GLFW_MOUSE_BUTTON_LAST,
        MB_1 = GLFW_MOUSE_BUTTON_1,
        MB_2 = GLFW_MOUSE_BUTTON_2,
        MB_3 = GLFW_MOUSE_BUTTON_3,
        MB_4 = GLFW_MOUSE_BUTTON_4,
        MB_5 = GLFW_MOUSE_BUTTON_5,
        MB_6 = GLFW_MOUSE_BUTTON_6,
        MB_7 = GLFW_MOUSE_BUTTON_7,
        MB_8 = GLFW_MOUSE_BUTTON_8,
    };
}