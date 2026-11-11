#pragma once
#include "MiniGameEngine/Core/BaseSystem.h"

namespace mge
{
    class ConvexHullSystem : public BaseSystem
    {
        
    public:
        bool Initialize() override;

        void FixedUpdate(float deltaTime) override ;
    };
}
