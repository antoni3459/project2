#pragma once
#include <string>
#include "../../../Utils/Interface/Log/ILogger.h"
namespace Engine::Reflection
{
	class ParameterInfo : public Interface::ILogger
	{
	private:
		std::string name = "";
		int position = 0;

	public:
		ParameterInfo() = default;
		ParameterInfo(const std::string& _name, int _position);
		virtual ~ParameterInfo() = default;
	public:
		std::string Name() const;
		int Position() const;

	public:
		PrimaryType::FString ToString() const override;

	};
}

