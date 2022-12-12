#pragma once
#include <string>

#define DECLARE_CLASS_INFO(parent)\
	public:\
		typedef parent super;
class Object
{
public:
	Object() = default;
	virtual ~Object() = default;

public:
	virtual std::string ToString()const;

};

