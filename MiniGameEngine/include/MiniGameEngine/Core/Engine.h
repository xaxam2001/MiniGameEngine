#pragma once
#include "InfraStructure.h"

namespace mge
{
    struct EngineContext;
    
    struct Engine : InfraStructure
    {
        struct EngineSystem
        {
            double targetFrameRate = 1.0 / 60.0;
            double accumulatedTime = 0.0;
            int maxIterations = 2;
            
            bool Create() {return true;}
            void Destroy() {}
            bool Initialize() {return true;}
            void Deinitialize() {}
            void Update(float deltaTime) {}
            void FixedUpdate(float deltaTime) {}
        };
        
        EngineSystem* m_AIEngine;
        
        void ProcessSystems(double elapsedTime);
        
        bool Initialize() final;
        
        void DeInitialize() final;
        
        void Update(EngineContext& context);
    };
}
