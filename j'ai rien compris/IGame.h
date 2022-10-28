#pragma once
#include "Object.h"

class IGame : public Object
{
	CLASS_INFO(Interfarce)
	DECLARE_TYPE(Object)
public:
	virtual void Test()
	{
		std::cout << "IGame " << std::endl;
	}
};