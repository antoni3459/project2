#include "Function.h"
#include "../../PrimaryType/FString/FString.h"

Engine::Reflection::Function::Function(const std::string& _name, const std::vector<ParameterInfo*>& _parameters)
{
    name = _name;
    parameters = _parameters;
}

Engine::PrimaryType::FString Engine::Reflection::Function::Name()
{
    return name.c_str();
}

std::vector<Engine::Reflection::ParameterInfo*> Engine::Reflection::Function::Parameters()
{
    return parameters;
}

Engine::PrimaryType::FString Engine::Reflection::Function::ToString() const
{
    std::string _result = "Name: " + name + "\n";
    for (const ParameterInfo* _parameter : parameters)
    {
        _result += _parameter->ToString();
        _result += " ";
    }
    return _result.c_str();
}
