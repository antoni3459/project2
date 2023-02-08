#include "Function.h"
#include "../../PrimaryType/FString/String.h"
#include "Parameter/ParameterInfo.h"

#pragma region constructor
Engine::Reflection::Function::Function(const std::string& _name, const std::vector<Engine::Reflection::ParameterInfo*>& _parameters)
{
    name = _name;
    parameters = _parameters;

}
#pragma endregion constructor

#pragma region method
Engine::PrimaryType::String Engine::Reflection::Function::Name() const
{
    return name.c_str();
}

std::vector<Engine::Reflection::ParameterInfo*> Engine::Reflection::Function::Parameters() const
{
    return parameters;
}
#pragma endregion method

#pragma region override
Engine::PrimaryType::String Engine::Reflection::Function::ToString() const
{
    std::string _result = "Name: " + name + "\n";
    for (const ParameterInfo* _parameter : parameters)
    {
        _result += _parameter->ToString();
        _result += " ";
    }
    return _result.c_str();
}
#pragma endregion override