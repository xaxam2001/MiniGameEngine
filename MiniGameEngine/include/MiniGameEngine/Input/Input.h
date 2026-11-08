#pragma once

#include "MiniGameEngine/Core/InfraStructure.h"

namespace mge
{
    struct Input : InfraStructure
    {
        bool bIsQuitButtonPressed = false;
        
        bool Initialize() final;
        void DeInitialize() final;
        void Update();
        
        bool GetQuitButtonState();
    };
}