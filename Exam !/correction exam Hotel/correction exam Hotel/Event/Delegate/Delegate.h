#pragma once
#include "../../Object/Object.h"

template<typename Res , typename... Args>
class Delegate : public Object
{
private:
	typedef Res(Object::* Function)(Args...);
	Function function = nullptr;
	Object* instance = nullptr;

public:
	Delegate() = default;
	Delegate(nullptr_t)
	{
		instance = nullptr;
		function = nullptr;
	}

public:
	template<class Class>
	void SetDynamic(Class* _instance, Res(Class::* ptr)(Args...))
	{
		if constexpr (!std::is_base_of_v<Object, Class>)
			throw std::exception("[Delegate] => Class must be inherited of Object");
		instance = _instance;
		function = reinterpret_cast<Function>(ptr);
	}

	Res Invoke(Args... _args)
	{
		if (function == nullptr || instance == nullptr)
			throw std::exception("[Delegate] => function or instance is null !");
		return (instance->*function)(_args...);
	}

	void operator=(nullptr_t)
	{
		instance = function = nullptr;
	}
};