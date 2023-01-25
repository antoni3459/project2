#pragma once
#include "../../Object/Object.h"

namespace Engine::PrimaryType
{
	class ValueType:public Object
	{
		DECLARE_CLASS_FLAGS(ValueType, Object,classFlags::Type)

	public:
		ValueType() = default;
		ValueType(const ValueType& _copy) = default;
		~ValueType()override = default;

	public:
		Object& operator=(const Object* _other)override
		{
			return super::operator=(_other);
		}
	};
}

