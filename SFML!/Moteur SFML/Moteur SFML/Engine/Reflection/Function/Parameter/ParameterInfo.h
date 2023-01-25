#pragma once
#include <string>
#include "../../../Object/Object.h"

namespace Engine::Reflection
{
	struct ParameterInfo:public Object
	{
		DECLARE_CLASS_INFO(ParameterInfo, Object)
	private:
		std::string name = "";
		int position = 0;

	public:
		ParameterInfo() = default;
		ParameterInfo(const std::string& _name, int _position);
		~ParameterInfo()override =default ;

	public:
		std::string Name()const;
		int Position();

	public:
		PrimaryType::String ToString()const;

	};
}

