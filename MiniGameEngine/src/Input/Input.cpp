#include "MiniGameEngine/Input/Input.h"

#include <iostream>
#include <GLFW/glfw3.h>

namespace mge
{
    bool Input::Initialize()
    {
#ifdef _DEBUG
        m_DebugName = "Input";
#endif
        return true;
    }

    void Input::DeInitialize()
    {
        
    }

    void Input::Update()
    {
        bIsQuitButtonPressed = IsQuitButtonPressed();
    }

    bool Input::IsQuitButtonPressed() const
    {
        if (!m_Window)
        {
            std::cerr << "[Input] current window not specified.\n";
        }
        
        if (glfwWindowShouldClose(m_Window)) return true;
        
        if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS) return true;
        
        return false;
    }
}
