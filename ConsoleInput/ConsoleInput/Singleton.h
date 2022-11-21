#pragma once

template <typename T>
class Singleton
{
private:
	static inline T* instance = nullptr;

public:
	Singleton() = default;


	~Singleton()
	{
		OnDestroy();
	}

public:
	virtual void OnDestroy() {}
	static T* Instance()
	{
		if (instance == nullptr)
			instance = new T();
		return instance;
	}

};