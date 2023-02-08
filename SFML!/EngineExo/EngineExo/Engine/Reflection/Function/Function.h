#pragma once
#include <string>
#include <vector>
#include "../../Utils/Interfarce/Log/ILogger.h"

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

	class Function:public Interfarce::ILogger
	{
#pragma region f/p
	private:
		std::string name = "";
		std::vector<ParameterInfo*> parameters = std::vector<ParameterInfo*>();
#pragma endregion f/p

#pragma region constructor/destructor
	public:
		Function() = default;
		Function(const std::string& _name, const std::vector<ParameterInfo*>& _parameters);
		virtual ~Function() = default;
#pragma endregion constructor/destructor

#pragma region method
	public:
		Engine::PrimaryType::String Name()const;
		std::vector<ParameterInfo*> Parameters()const;
#pragma endregion method

#pragma region override
	public:
		virtual Engine::PrimaryType::String ToString() const override;
#pragma endregion override
	};
}

