#pragma once
#include "Object.h"

namespace Core
{
    namespace PrimitiveType
    {
        class FString;
    }
    namespace Diagnostics
    {
        class O3DLIBRAIRY_API Process : public Object
        {
        public:
            static void Start(const PrimitiveType::FString& _path, const PrimitiveType::FString& _parameters);
        };
    }


}
