#pragma once
#include "../PrimaryType/FString/FString.h"
#include <string>

#define INDEX_NONE -1

template<typename T>
inline Engine::PrimaryType::FString ToString(T item)
{
	if constexpr (std::is_base_of_v<Engine::Object, T>)
	{
		return item.ToString();
	}
	else
	{
		return std::to_string(item).c_str();
	}
}


template<typename T>
inline Engine::PrimaryType::FString ToString(T* item)
{
	return item->ToString();
}
