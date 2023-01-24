#pragma once
#include "../../Object/Object.h"
#include "../../Utils/DebugMacro.h"
#include <typeinfo>

namespace Engine::Event
{
	template<typename Res, typename... Params>
	class Delegate:public Object
	{
	private:
		typedef Res(Object::* Function)(Params...);
		Function function = nullptr;
		Object* instance = nullptr;

	public:
		Delegate(nullptr_t)
		{
			function = nullptr;
			instance = nullptr;
		}

		template<typename Class>
		Delegate(Class* _inctance, Res(CLass::* ptr)(Params...);

	public:
		template<typename Class>
		Delegate(Class* _instance, Res(Class::* ptr)(Params...))
		{
			checkBaseOf(Object, Class)
				instance = _instance;
			function = reinterpret_cast<Function>(ptr);
		}

	public:
		void SetDynamic(nullptr_t)
		{
			function = nullptr;
			instance = nullptr;
		}
		template<typename Class>
		void SetDynamic(Class* _instance, Res(Class::* ptr)(Params...))
		{
			checkBaseOf(Object, Class)
				instance = _instance;
			function = reinterpret_cast<Function>(ptr);
		}
		bool IsValid()
		{
			return instance != nullptr && function != nullptr;
		}
		Res Invoke(Params... params)
		{
			return (instance->*function)(_params...);
		}
		Object* Instance() const
		{
			return instance;
		}
		void* GetAdress() const
		{
			return (void*&)function;
		}

	public:
		PrimaryType::Boolean operator(const Delegate& _other)
		{
			return GetAdress() == _other.GetAdress()
		}
		PrimaryType::Boolean operator(Res(Class::* ptr)(Params...))
		{
			return GetAdress() == (void*&)ptr;
		}
		Delegate& operator=(const Delegate& _other)
		{
			instance = _other.instance;
			function = _other.function;
			return *this;
		}
		Delegate& operator=(nullptr_t)
		{
			instance = nullptr;
			function = nullptr;
			return *this;
		}
		Res operator()(Params... _params)
		{
			return (instance->*function)(_params...);
		}
	};

}
