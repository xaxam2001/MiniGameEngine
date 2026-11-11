#pragma once

namespace mge
{
    class Clock;
    class Input;
    class Engine;
    
    struct EngineContext
    {
        Clock& clock;
        Input& input;
        Engine& engine;
        
        // global access point
        static EngineContext* Instance;
        
        EngineContext(Clock& c, Input& i, Engine& e) : clock(c), input(i), engine(e) {}
        ~EngineContext() = default;
        
        Clock& Clock() const {return clock;}
        Input& Input() const {return input;}
        Engine& Engine() const {return engine;}
    };
}