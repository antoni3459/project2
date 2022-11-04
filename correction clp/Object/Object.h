#pragma once
#include <string>
class Object
{
#pragma region constructor
public:
	Object() = default;
	virtual ~Object() = default;
#pragma endregion constructor

	virtual std::string ToString()const; 

};

