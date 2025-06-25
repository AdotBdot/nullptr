#pragma once

#include "Mapping.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

#include <functional>
#include <map>

namespace Input
{
    enum class MouseMode
    {
        Normal,
        Hidden,
        Disabled
    };

    //TODO: Process scroll input
    class MouseHandler
    {
    private:
        std::map<Mapping, std::function<void()>> Mappings_;

    public:
        MouseHandler();
        ~MouseHandler();

        void setMouseMode(GLFWwindow *window, const MouseMode &mouseMode);
        void setRawMouseInput(GLFWwindow *window, const bool &rawMouseInput);
        void setStickyMouseButtons(GLFWwindow *window, const bool &stickyMouseButtons);
        glm::dvec2 getMousePos(GLFWwindow *window) const;

        void bind(Mapping mapping, std::function<void()> function);
        void processKeyInput(const Mapping &input);
    };
}