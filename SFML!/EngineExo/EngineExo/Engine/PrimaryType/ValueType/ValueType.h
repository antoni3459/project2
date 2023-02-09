#pragma once
#include "../../Reflection/Utils/ReflectionUtils.h"
#include "../../Object/Object.h"
namespace Engine
{
	namespace PrimaryType
	{
		UCLASS()
		class ValueType : public Object
		{
			DECLARE_CLASS_INFO_FLAGS(ValueType, Object, ClassFlags::Type)

#pragma region constructor/destructor
		public:
			ValueType() = default;
			~ValueType() override = default;
#pragma endregion constructor/destructor

#pragma region operator
		public:
			virtual Object& operator=(const Object* _obj) override;
#pragma endregion operator
		};
	}
}

