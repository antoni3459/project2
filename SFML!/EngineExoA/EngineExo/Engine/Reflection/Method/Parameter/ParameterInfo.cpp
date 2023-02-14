#include "ParameterInfo.h"
#include "../../../PrimaryType/FString/FString.h"
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

int Engine::Reflection::ParameterInfo::Position() const
{
    return position;
}

Engine::PrimaryType::FString Engine::Reflection::ParameterInfo::ToString() const
{
    return std::format("Name: {}, Position: {}", name, position).c_str();
}

