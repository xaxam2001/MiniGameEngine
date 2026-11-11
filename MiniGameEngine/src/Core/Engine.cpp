#include "MiniGameEngine/Core/Engine.h"

#include <iostream>

#include "MiniGameEngine/Core/EngineContext.h"
#include "MiniGameEngine/Math/ConvexHullSystem.h"
#include "MiniGameEngine/Time/Timer.h"

namespace mge
{
    bool Engine::Initialize()
    {
#ifdef _DEBUG
        m_DebugName = "Engine";
#endif
        
        m_Systems.push_back(new ConvexHullSystem());
        
        for (auto* system : m_Systems)
        {
            std::cout << "Initializing system \n";
            system->Create();
            system->Initialize();
        }
        
        return true;
    }

    void Engine::DeInitialize()
    {
        for (auto* system : m_Systems)
        {
            system->DeInitialize();
            system->Destroy();
            delete system;
        }
        m_Systems.clear();
    }

    void Engine::Update(const EngineContext& context) const
    {
        double elapsedTime = context.Clock().ElapsedTime;

        elapsedTime = std::min(elapsedTime, 0.1); // clamp elapsed time in case of massing lags
        
        ProcessSystems(elapsedTime);
    }

    void Engine::ProcessSystems(double elapsedTime) const
    {
        float deltaTime = static_cast<float>(elapsedTime);
        
        for (auto* system : m_Systems)
        {
            system->accumulatedTime += elapsedTime;
            system->Update(deltaTime);
            
            int loops = system->maxIterations;
            
            // this ensure that FixedUpdate is executed only when accumulated time is longer than the target frame rate
            // when the frame computed faster than targetFrameRate, it won't execute this frame
            // when the frame took more than targetFrameRate to compute, it will execute multiple time to catch up computation
            while (system->accumulatedTime > system->targetFrameRate && loops >0)
            {
                system->accumulatedTime -= system->targetFrameRate;
                system->FixedUpdate(static_cast<float>(system->targetFrameRate));
                --loops;
            }
        }
        
    }
}
