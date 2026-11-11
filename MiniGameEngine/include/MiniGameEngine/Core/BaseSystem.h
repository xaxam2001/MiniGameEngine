#pragma once

namespace mge
{
    struct BaseSystem
    {
        double targetFrameRate = 1.0 / 60.0;
        double accumulatedTime = 0.0;
        int maxIterations = 2;
        
        virtual ~BaseSystem() = default;
        
        // Virtual methods with default empty implementations
        virtual bool Create() { return true; }
        virtual void Destroy() {}
        virtual bool Initialize() { return true; }
        virtual void DeInitialize() {}
        virtual void Update(float deltaTime) {}
        virtual void FixedUpdate(float deltaTime) {}
    };
}