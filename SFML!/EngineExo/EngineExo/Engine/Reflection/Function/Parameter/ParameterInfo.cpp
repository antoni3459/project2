#include "ParameterInfo.h"
#include "../../../PrimaryType/FString/String.h"

#include <format>

Engine::Reflection::ParameterInfo::ParameterInfo(const std::string& _name, int _position)
{
    name = _name;
    position = _position;

}

std::string Engine::Reflection::ParameterInfo::Name() const
{
    return name;
}

int Engine::Reflection::ParameterInfo::Position()
{
    return position;
}
