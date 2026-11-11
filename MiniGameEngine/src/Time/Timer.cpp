#include "MiniGameEngine/Time/Timer.h"

#include <iostream>

namespace mge
{
    bool Clock::Initialize()
    {
#ifdef _DEBUG
        m_DebugName = "Clock";
#endif
        TimePointAtStartup = TimeSource::now();
        PreviousTimePoint = TimePointAtStartup;
        return true;
    }

    void Clock::DeInitialize()
    {
        
    }

    void Clock::Update()
    {
        CurrentTimePoint = TimeSource::now();
        
        TimeSinceStartup = std::chrono::duration<double>(CurrentTimePoint - TimePointAtStartup).count();
        ElapsedTime = std::chrono::duration<double>(CurrentTimePoint - PreviousTimePoint).count();
        
        PreviousTimePoint = CurrentTimePoint;

        for (size_t i = 0; i < m_Timers.size(); i++)
        {
            auto& pair = m_Timers[i];
            Timer& timer = pair.first;
            std::function<void()>& function = pair.second;
            
            timer.CurrentTime += ElapsedTime;
            
            if (timer.CurrentTime > timer.Delay)
            {
                function();
                
                timer.CurrentTime -= timer.Delay;
                
                if (!timer.bRepeat)
                {
                    // swap and pop
                    m_Timers[i] = m_Timers.back();
                    m_Timers.pop_back();
                    i--;
                }
            }
        }
        
        if (!m_PendingTimers.empty())
        {
            m_Timers.insert(m_Timers.end(), m_PendingTimers.begin(), m_PendingTimers.end());
            m_PendingTimers.clear();
        }
    }
}
