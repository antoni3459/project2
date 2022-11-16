#pragma once
#include "Object.h"
#include "O3DLibrary.h"
namespace Core
{
	namespace PrimitiveType
	{
		class Booleain sealed :public Object
		{

		private:
			bool value = false;
		public:
			Booleain() = default;
			O3DLIBRARY_API Booleain(const bool _value);
			O3DLIBRARY_API Booleain(const Booleain& _copy);
			O3DLIBRARY_API FString ToString() const override;

		public:
			Booleain operator==(const Booleain& _other) const;
			Booleain operator !=(const Booleain& _other)const;
			operator bool()const;
			Booleain operator!()const;
		};
	}
}
