#pragma once
#include <string>
class Object
{
#pragma region constructeur
public:
	Object() = default;
	virtual ~Object()=default;

	virtual std::string ToString() const;


};

