#pragma once
#include <string>

class Object
{
	#pragma region constructeur
public:
	Object() = default;
	virtual ~Object() = default;
#pragma endregion constructeur

#pragma region constructeur
public:
	virtual std::string ToString() const;
#pragma endregion constructeur



};

