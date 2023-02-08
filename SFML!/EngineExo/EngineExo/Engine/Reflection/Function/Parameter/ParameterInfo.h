#pragma once
#include <string>
#include "../../../Object/Object.h"



namespace Engine::Reflection
{
	class ParameterInfo :public Interfarce::ILogger
	{

#pragma region f/p
	private:
		std::string name = "";
		int position = 0;
#pragma endregion f/p

#pragma region constructor
	public:
		ParameterInfo() = default;
		ParameterInfo(const std::string& _name, int _position);
		ParameterInfo(const ParameterInfo&) = default;
		virtual ~ParameterInfo() = default;
#pragma endregion constructor

#pragma region method
	public:
		std::string Name()const;
		int Position();
#pragma endregion method

#pragma region override
	public:
		PrimaryType::String ToString()const override;
#pragma endregion override
	};
}

