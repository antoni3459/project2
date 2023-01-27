#pragma once
#include "../../Utils/DebugMacro.h"
#include "../../Object/Object.h"

namespace Engine::Event
{
	template<typename Res, typename... Params>
	class Delegate : Object
	{
		DECLARE_CLASS_INFO(Delegate, Object)

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
		Delegate(Class* _instance, Res(Class::* ptr)(Params...))
		{
			checkBaseOf(Object, Class)
			instance = _instance;
			function = reinterpret_cast<Function>(ptr);
		}

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

		Res Invoke(Params... _params)
		{
			return (instance->*function)(_params)
		}

		PrimaryType::Boolean IsValid() const
		{
			return instance != nullptr && function != nullptr;
		}

		void* GetAdress() const
		{
			return (void*&)function;
		}

		Primary::Boolean operator==(const Delegate& _other)
		{
			return GetAddress() == _other.GetAdress();
		}

		template<typename Class>
		Primary::Boolean operator==(Res(Class::* ptr)(Params...))
		{

			return *this;
		}

		Delegate& operator=(nullptr_t)
		{
			function = nullptr;
			instance = nullptr;
			return *this;
		}

		Res operator() (Params... _params)
		{
			return (instance->*function)(_params...);
		}
	};
}