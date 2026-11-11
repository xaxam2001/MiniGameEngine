#include "MiniGameEngine/Math/ConvexHullSystem.h"

#include <iostream>

#include "MiniGameEngine/Core/EngineContext.h"
#include "MiniGameEngine/Time/Timer.h"

namespace mge
{
    bool ConvexHullSystem::Initialize()
    {
        std::cout << "Convex Hull logic ready.\n";
        
        Timer testTimer{ 1.0, 0.0, true };

        EngineContext::Instance->Clock().AddTimer(testTimer, []() {
            std::cout << "Convex Hull system ticking every second!\n";
        });
        
        return true;
    }

    void ConvexHullSystem::FixedUpdate(float deltaTime)
    {
        
    }
}
