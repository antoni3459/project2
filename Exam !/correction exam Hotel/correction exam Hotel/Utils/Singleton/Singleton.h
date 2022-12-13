#pragma once
#include "../../Object/Object.h"

template<typename T>
class Singleton :public Object
{
	DECLARE_CLASS_INFO(Object)

private:
	static inline T* instance = nullptr;

public:
	Singleton() = default;
	virtual ~Singleton()
	{
		OnDestroy();
		delete instance;
		instance = nullptr;
	}

protected:
	virtual void OnDestroy()
	{

	}
public:
	static T* Instance()
	{
		if (instance == nullptr)
			instance = new T();
		return instance;
	}
	
};