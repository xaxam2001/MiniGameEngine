#pragma once
#include <vector>

#include "Engine.h"
#include "EngineContext.h"
#include "InfraStructure.h"
#include "MiniGameEngine/Input/Input.h"
#include "MiniGameEngine/Time/Timer.h"

struct GLFWwindow;  

namespace mge
{    
    class Application
    {
        std::vector<InfraStructure*> m_cores;
        
        EngineContext& m_context;
        uint64_t m_frameIndex = 0;
        bool m_bQuitApp = false;
        
        GLFWwindow* m_window = nullptr;
        
    public: 
        Application(EngineContext& context) : m_context(context) {}
        Application() : Application(CreateContext()) {}
        Application(Application& app) = delete; // Safety, crash the app if try to pass the Application by value instead of reference 
        
        static EngineContext& CreateContext();
        
        bool Create();
        void Destroy();
        
        bool Initialize();
        void DeInitialize();
        
        void Update() const;
        
        void Run();
    };
}
