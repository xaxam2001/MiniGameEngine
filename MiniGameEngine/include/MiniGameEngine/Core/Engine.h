#pragma once
#include <vector>

#include "BaseSystem.h"
#include "InfraStructure.h"

namespace mge
{
    struct EngineContext;
    
    class Engine : public InfraStructure
    {        
        std::vector<BaseSystem*> m_Systems;
        
        void ProcessSystems(double elapsedTime) const;
        
    public:
        bool Initialize() final;
        void DeInitialize() final;
        
        void Update(const EngineContext& context) const;
    };
}
