#pragma once
#include "Object.h"
#include "O3DLibrary.h"
namespace Core
{
	namespace PrimitiveType
	{
		class boolean sealed :public Object
		{

		private:
			bool value = false;
		public:
			boolean() = default;
			O3DLIBRARY_API boolean(const bool _value);
			O3DLIBRARY_API boolean(const boolean& _copy);
			FString ToString() const override;

		public:
			boolean operator==(const boolean& _other) const;
			boolean operator !=(const boolean& _other)const;
			operator bool()const;
			boolean operator!()const;
		};
	}
}


