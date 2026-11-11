#include "MiniGameEngine/Core/Application.h"

#include <iostream>
#include <thread>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "MiniGameEngine/Core/Utils.h"

namespace mge
{
    EngineContext& Application::CreateContext()
    {
        Clock* clock = new Clock;
        Input* input = new Input;
        Engine* engine = new Engine;
            
        static EngineContext context(*clock, *input, *engine);
        
        EngineContext::Instance = &context;
        
        return context;
    }

    bool Application::Create()
    {
        m_cores.reserve(3);
        m_cores.emplace_back(&m_context.clock);
        m_cores.emplace_back(&m_context.input);
        m_cores.emplace_back(&m_context.engine);
        
        return true;
    }

    void Application::Destroy()
    {
        for (auto* core : make_reverse(m_cores))
        {
#ifdef _DEBUG
            std::cout << "destroying core " << core->DebugName().c_str() << "\n";
#endif
            
            delete core;
        }
        
        m_cores.clear(); // resize to 0, but capacity stays the same
        m_cores.shrink_to_fit(); // free memory, reduce capacity to 0
    }

    bool Application::Initialize()
    {
        bool bAllOk = true;
        
        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW\n";
            bAllOk = false;
        }

        m_window = glfwCreateWindow(
            1280,
            720,
            "MyEngine",
            nullptr,
            nullptr
        );

        if (!m_window)
        {
            std::cerr << "Failed to create GLFW window\n";
            bAllOk = false;
        }

        glfwMakeContextCurrent(m_window);
        
        if (glewInit() != GLEW_OK)
        {
            std::cerr << "Failed to initialize GLEW\n";
            bAllOk = false;
        }

        std::cout << "OpenGL version: "
                  << glGetString(GL_VERSION) << '\n';
        
        // give input core access to the current window pointer
        m_context.input.SetWindow(m_window);
        
        for (auto* core : m_cores)
        {
#ifdef _DEBUG
            std::cout << "initializing core " << core->DebugName().c_str() << "\n";
#endif
            bAllOk &= core->Initialize();
        }
        
        return bAllOk;
    }

    void Application::DeInitialize()
    {
        for (auto* core : make_reverse(m_cores))
        {
            core->DeInitialize();
        }
        
        if (m_window) glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void Application::Update() const
    {
        m_context.Clock().Update();
        m_context.Input().Update();
        m_context.Engine().Update(m_context);
    }

    void Application::Run()
    {
        bool bInitOk = Create();
        
        if (bInitOk) bInitOk &= Initialize();
        
        m_bQuitApp = !bInitOk;
        
        while (!m_bQuitApp)
        {
            Update();
            
            glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(m_window);
            glfwPollEvents();
            
            m_bQuitApp = m_context.Input().IsQuitButtonPressed();
            
            m_frameIndex++;
        }
        
        DeInitialize();
        
        Destroy();
    }
}
