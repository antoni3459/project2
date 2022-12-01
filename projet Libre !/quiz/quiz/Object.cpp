#include "Object.h"
#include <typeinfo>

std::string Object::ToString()
{
	std::string _className = typeid(*this).name();
	return _className.substr(_className.find(' ') + 1);
}
