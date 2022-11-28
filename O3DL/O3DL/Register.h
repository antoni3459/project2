#pragma once
#include <map>
#include <vector>
#include "Object.h"
#include <string>

namespace Core
{
	class Register : public Object
	{
#pragma region f/p

	private:
		std::map<std::string, Core::Object*> regiValue = std::map<std::string, Core::Object*>();
		std::map<std::string, bool> regiType = std::map<std::string, bool>();

#pragma endregion f/p

#pragma region constructors

	public:
		Register() = default;
		~Register() = default;

#pragma endregion constructors

#pragma region methods

	public:
		std::map<std::string, Core::Object*> RegisterValue(std::string _name);
		std::map<std::string, bool> RegisterType(std::string _name);

#pragma endregion methods

	};

}

