#pragma once

#include <string>

namespace mge
{
    class InfraStructure
    {
    public:
        
#ifdef _DEBUG
        std::string m_DebugName;
        const std::string& DebugName() {return m_DebugName;}
#endif
    
        virtual bool Initialize() = 0;
        virtual void DeInitialize() = 0;
    };
}