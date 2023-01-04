#pragma once
#include "Object.h"
#include "FString.h"
#include <Windows.h>

namespace Core
{
    namespace Net
    {
        class O3DLIBRAIRY_API Uri : public Object
        {
#pragma region f/p

        private:
            PrimitiveType::FString path = "";

#pragma endregion f/p

#pragma region constructor

        public:
            Uri() = default;
            Uri(const PrimitiveType::FString& _path);
            Uri(const Uri& _copy);

#pragma endregion constructor

        public:
            PrimitiveType::FString Path();

#pragma region override

        public:
            PrimitiveType::FString ToString()const override;
            int GetHashCode()const override;

#pragma endregion override

#pragma region operator

        public:
            operator LPCWSTR()const;

#pragma endregion operator

        };
    }
}

