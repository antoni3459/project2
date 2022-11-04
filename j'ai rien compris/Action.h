#include "Action.h"
#include "Action.h"
#pragma once
#include <iostream>
#include <vector>
#include "Exception.h"
class Object;

template<typename... Args> // les ... permet de mettre autant de template qu'on vaut dans le main
class Action
{
#pragma region f/p

private:
	typedef void (Object::* Function)(Args...);
	std::vector<Function> functions = std::vector<Function>();

	#pragma region f/p

#pragma region f/p
public:
	Action(nullptr_t(_ptr));
	template<typename Class>
	Action(void(Class::* _ptr)(Args...));
	~Action();

#pragma region f/p
public:
	

	void Invoke(Object* _instance, Args... _value);

public:
	template<typename Class>
	void operator+=(void (Class::* _ptr)(Args...));
	template<typename Class>
	void operator-=(void (Class::* _ptr)(Args...));

	template<typename Class>
	void operator=(void (Class::* _ptr)(Args...));

};


template<typename Res, typename ...Args>
inline Action<Res, ...Args>::Action(nullptr_t)
{
}

template<typename... Args>
inline Action<Args...>::~Action()
{
	functions.clear();
}

template<typename Res, typename ...Args>
inline size_t Action<Res, Args...>::FindIndex(const Action<Res, Args...>& _function)
{
	for (size_t i=0; i<
	return -1;
}

template<typename... Args>
inline void Action<Args...>::Invoke(Object* _instance, Args... _value)
{
	for (size_t i = 0; i < functions.size(); i++)
	{
		(_instance->*functions[i])(_value...);
	}
}

template<typename... Args>
template<typename Class>
inline Action<Args...>::Action(void(Class::* _ptr)(Args...))
{
	functions.push_back(reinterpret_cast<Function>(_ptr));
}

template<typename... Args>
template<typename Class>
inline void Action<Args...>::operator+=(void(Class::* _ptr)(Args...))
{
	functions.push_back(reinterpret_cast<Function>(_ptr));
}

template<typename... Args>
template<typename Class>
inline void Action<Args...>::operator-=(void(Class::* _ptr)(Args...))
{
	Function _function = reinterpret_cast<Function>(_ptr);
	for (size_t i = 0; i < functions.size(); i++)
	{
		if (functions[i] == _function)
		{
			functions.erase(functions.begin() + i);
			return;
		}
	}
}

template<typename... Args>
template<typename Class>
inline void Action<Args...>::operator=(void(Class::* _ptr)(Args...))
{
	functions.clear();
	functions.push_back(reinterpret_cast<Function>(_ptr));
}
template<typename... Args>
inline Action<Args...>::Action(nullptr_t (_ptr))
{
	functions.push_back(reinterpret_cast<Function>(_ptr));
}

