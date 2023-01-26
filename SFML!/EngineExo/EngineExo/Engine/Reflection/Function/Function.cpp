#include "Function.h"
#include "../../PrimaryType/FString/String.h"
#include "Parameter/ParameterInfo.h"

Engine::Reflection::Function::Function(const std::string& _name, const std::vector<Engine::Reflection::ParameterInfo*>& _parameters)
{
    name = _name;
    parameters = _parameters;

}

Engine::PrimaryType::String Engine::Reflection::Function::Name() const
{
    return name.c_str();
}

std::vector<Engine::Reflection::ParameterInfo*> Engine::Reflection::Function::Parameters() const
{
    return parameters;
}
