#pragma once
#include <chrono>
#include <functional>
#include <vector>

#include "MiniGameEngine/Core/InfraStructure.h"


namespace mge
{
    struct TimeSource
    {
        using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
        static TimePoint now() {return std::chrono::high_resolution_clock::now();}
    };
    
    struct Timer
    {
        double Delay;
        double CurrentTime;
        bool bRepeat;
    };
    
    struct Clock : InfraStructure
    {
        std::vector<std::pair<Timer, std::function<void()>>> m_Timers;
        
        TimeSource::TimePoint TimePointAtStartup;
        TimeSource::TimePoint PreviousTimePoint;
        TimeSource::TimePoint CurrentTimePoint;
        
        double TimeSinceStartup = 0.0;
        double ElapsedTime = 0.0;
        
        bool Initialize() final;
        void DeInitialize() final;
        
        void Update();
        
        void AddTimer(Timer& timer, std::function<void()> event)
        {
            m_Timers.emplace_back(timer, event);
        }
    };
}
