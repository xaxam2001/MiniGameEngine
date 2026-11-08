#pragma once

namespace mge
{
    struct Clock;
    struct Input;
    struct Engine;
    
    struct EngineContext
    {
        Clock& clock;
        Input& input;
        Engine& engine;
        
        EngineContext(Clock& c, Input& i, Engine& e) : clock(c), input(i), engine(e) {}
        ~EngineContext() = default;
        
        Clock& Clock() const {return clock;}
        Input& Input() const {return input;}
        Engine& Engine() const {return engine;}
    };
}