#pragma once
#include "../Object/Object.h"

template<typename T>
class Singleton : public Object
{
private:
	static inline T* instance = nullptr;

public:
	Singleton() = default;
	virtual ~Singleton()override
	{
		OnDestroy();
		delete instance;
	}

public:
	static T* Instance()
	{
		if (instance == nullptr)instance = new T();
		return instance;
	}
	virtual void OnDestroy() {}

};