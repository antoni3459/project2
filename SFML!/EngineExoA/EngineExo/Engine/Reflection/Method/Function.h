#pragma once
#include <string>
#include <vector>
#include "../../Utils/Interface/Log/ILogger.h"

namespace Engine
{

	namespace PrimaryType
	{
		class FString;
	}

	namespace Reflection
	{
		class ParameterInfo;
		class Function : public Interface::ILogger
		{
		private:
			std::string name = "";
			std::vector<ParameterInfo*> parameters = std::vector<ParameterInfo*>();

		public:
			Function() = default;
			Function(const std::string& _name, const std::vector<ParameterInfo*>& _parameters);
			virtual ~Function() = default;


		public:
			PrimaryType::FString Name();
			std::vector<Engine::Reflection::ParameterInfo*> Parameters();

		public:
			PrimaryType::FString ToString() const override;

		};
	}
}
