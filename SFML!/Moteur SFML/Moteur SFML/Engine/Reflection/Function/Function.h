#pragma once
#include <string>
#include <vector>

namespace Engine
{
	namespace PrimaryType
	{
		class String;
	}
}

namespace Engine::Reflection
{
	class ParameterInfo;

	class Function
	{
	private:
		std::string name = "";
		std::vector<ParameterInfo*> parameters = std::vector<ParameterInfo*>();

	public:
		Function() = default;
		Function(const std::string& _name, const std::vector<ParameterInfo*>& _parameters);
		virtual ~Function() = default;

	public:
		 Engine::PrimaryType::String Name()const;
		 std::vector<ParameterInfo*> Parameters()const;
	};
}

