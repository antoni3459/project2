#pragma once
#include <string>

#pragma warning(disable: 4804)
#pragma warning(disable: 4244)

#define DECLARE_CLASS_INFO(current, parent) \
	public:\
		typedef current self;\
		typedef parent super;

namespace Core
{
	class Object
	{
	public:
		Object() = default;
		Object(const Object&) = default;
		virtual ~Object() = default;
	public:
		virtual std::string ToString() const;
	};
}

