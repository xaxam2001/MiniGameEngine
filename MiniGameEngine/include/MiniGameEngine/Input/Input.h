#pragma once

#include "MiniGameEngine/Core/InfraStructure.h"

struct GLFWwindow;

namespace mge
{
    class Input : public InfraStructure
    {
        GLFWwindow* m_Window = nullptr;
        bool bIsQuitButtonPressed = false;
        
    public:
        void SetWindow(GLFWwindow* window) { m_Window = window; }
        
        bool Initialize() final;
        void DeInitialize() final;
        void Update();
        
        bool IsQuitButtonPressed() const;
    };
}