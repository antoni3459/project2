#pragma once
#include "../../Object/Object.h"
class Client : public Object
{
	DECLARE_CLASS_INFO(Object)

private:
	std::string firstName = "";
	std::string lastName = "";

public:
	Client() = default;
	Client(const std::string& _firstName, const std::string& _lastName);
	Client(const Client& _copy);

public:
	std::string FirstName()const;
	std::string LastName()const;
};

