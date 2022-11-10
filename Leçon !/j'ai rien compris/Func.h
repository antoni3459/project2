#pragma once

class Object;

typedef decltype(nullptr) nullptr_t;


template<typename Out, typename... Args>

class Func
{

#pragma region typedef 
private :
	typedef Out(Object::* Function)(Args...);
	Function function = nullptr;

#pragma endregion typedef 

#pragma region constructor
public:
	Func(nullptr_t);
	template<typename Class>
	Func(Out(Class::* _ptr)(Args...));
	~Func();

#pragma region constructor

#pragma region method
public:
	Out Invoke(Object* _instanc, Args...);

#pragma region method

#pragma region operator

	void operator=(nullptr_t);
	template<typename Class>
	void operator=(Out(Class::* _ptr)(Args...));

#pragma region operator
};

template<typename Out, typename... Args>
inline Func<Out, Args...>::Func(nullptr_t)
{
	function = nullptr;
}

template<typename Out, typename... Args>
inline Func<Out, Args...>::~Func()
{
	function = nullptr;
}

template<typename Out, typename... Args>
inline Out Func<Out, Args...>::Invoke(Object* _instanc, Args... _args)
{
	return (_instanc->*function)(_args...);
}

template<typename Out, typename... Args>
inline void Func<Out, Args...>::operator=(nullptr_t)
{
}

template<typename Out, typename... Args>
template<typename Class>
inline Func<Out, Args...>::Func(Out(Class::* _ptr)(Args...))
{
	function = reinterpret_cast<Function>(_ptr);
}


template<typename Out, typename... Args>
template<typename Class>
inline void Func<Out, Args...>::operator=(Out(Class::* _ptr)(Args...))
{
	function = reinterpret_cast<Function>(_ptr);
}
