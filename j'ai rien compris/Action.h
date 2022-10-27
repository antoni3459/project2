#pragma once
#include <iostream>
#include <vector>
class Object;

template<typename T>
class Action
{
#pragma region f/p

private:
	typedef void (Object::* Function)(T);
	std::vector<Function> functions = std::vector<Function>();
	#pragma region f/p
#pragma region f/p
public:
	Action(nullptr_t);
	template<typename Class>
	Action(void(Class::* _ptr)(T));
	~Action();
#pragma region f/p
public:
	void Invoke(Object* _instance, T _value);

public:
	template<typename Class>
	void operator+=(void (Class::* _ptr)(T));
	template<typename Class>
	void operator-=(void (Class::* _ptr)(T));

	template<typename Class>
	void operator=(void (Class::* _ptr)(T));

};


template<typename T>
inline Action<T>::~Action()
{
	functions.clear();
}

template<typename T>
inline void Action<T>::Invoke(Object* _instance, T _value)
{
	for (size_t i = 0; i < functions.size(); i++)
	{
		(instance->*functions[i])(_value);
	}
}

template<typename T>
template<typename Class>
inline Action<T>::Action(void(Class::* _ptr)(T))
{
	functions.push_back(reinterpret_cast<Function>(_ptr));
}

template<typename T>
template<typename Class>
inline void Action<T>::operator=(void(Class::* _ptr)(T))
{
	functions.clear();
	functions.push_back(reinterpret_cast<Function>(_ptr));
}

template<typename T>
template<typename Class>
inline void Action<T>::operator=(void(Class::* _ptr)(T))
{
     
}

template<typename T>
inline void Action<T>::Invoke(Object* _instance, T _value)
{
	for (size_t i = 0; i < functions.size(); i++)
	{
		(instance->*functions[i])(_value);
	}
}
template<typename T>
inline Action<T>::Action(nullptr_t)
{
	functions.push_back(reinterpret_cast<Function>(_ptr));
}

