#pragma once
#include "../../Object/Object.h"
namespace Engine
{
	namespace PrimaryType
	{
		class ValueType : public Object
		{
			DECLARE_CLASS_INFO_FLAGS(ValueType, Object, ClassFlags::Type)

			ValueType() = default;
			ValueType(const ValueType& _copy) = default;
			~ValueType() override = default;
			

		public:
			virtual Object& operator=(const Object* _obj) override;
		};
	}
}

