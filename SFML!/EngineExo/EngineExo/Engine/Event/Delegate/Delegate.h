#pragma once
#include "../../Utils/DebugMacro.h"
#include "../../Object/Object.h"
#include "../../PrimaryType/Boolean/Boolean.h"

namespace Engine::Event
{
	template<typename Res, typename... Params>
	class Delegate : Object
	{
		DECLARE_CLASS_INFO(Delegate, Object)

#pragma region f/p
	private:
		typedef Res(Object::* Function)(Params...);
		Function function = nullptr;
		Object* instance = nullptr;
#pragma endregion f/p

#pragma region f/p
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
#pragma endregion f/p

#pragma region method
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

		Res Invoke(Params... _params)
		{
			return (instance->*function)(_params...);
		}

		Engine::PrimaryType::Boolean IsValid() const
		{
			return instance != nullptr && function != nullptr;
		}

		void* GetAdress() const
		{
			return (void*&)function;
		}

		Engine::PrimaryType::Boolean operator==(const Delegate& _other)
		{
			return GetAdress() == _other.GetAdress();
		}
#pragma endregion method

#pragma region operator
		template<typename Class>
		Engine::PrimaryType::Boolean operator==(Res(Class::* ptr)(Params...))
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
#pragma endregion operator
	};
}