#pragma once
#include "../Function.h"
#include "../../Flags/BindingFlags.h"

namespace Engine
{
	class Object;
	namespace Reflection
	{
		template<typename Res, typename... Params>
		class MethodInfo : public Function
		{
		private:
			typedef Res(Object::* FunctionType)(Params...);
			typedef Res(*StaticFunctionType)(Params...);
			FunctionType function = nullptr;
			StaticFunctionType staticFunction = nullptr;
			BindingFlags flags = BindingFlags::NoPublic;

		public:

			MethodInfo() = default;
			template<typename Class>
			MethodInfo(const std::string _name, Res(Class::* ptr)(Params...), const std::vector<ParameterInfo*>& _parameters, const BindingFlags _flags) : Function(_name, _parameters)
			{
				if constexpr (!std::is_base_of_v<Object, Class>)
					throw std::exception("Class must be inherited of Object");
				function = reinterpret_cast<FunctionType>(ptr);
				flags = _flags;
			}
			MethodInfo(const std::string& _name, Res(*ptr)(Params...), const std::vector<ParameterInfo*>& _params, const BindingFlags& _flags)
				: Function(_name, _params)
			{
				staticFunction = ptr;
				flags = _flags;
			}

		public:
			BindingFlags Flags()
			{
				return flags;
			}

			Res Invoke(Object* _instance, Params..._params)
			{
				if (function != nullptr)
					return (_instance->*function)(_params...);
				return staticFunction(_params...);
			}
			void* GetAddress() const
			{
				if (function != nullptr)
					return (void*&)function;
				return (void*&)staticFunction;
			}


			bool operator==(nullptr_t)
			{
				return function == nullptr || staticFunction == nullptr;
			}
			bool operator!=(nullptr_t)
			{
				return function != nullptr || staticFunction != nullptr;
			}

			bool operator==(const MethodInfo& _other)
			{
				return GetAddress() == _other.GetAddress();
			}
			bool operator!=(const MethodInfo& _other)
			{
				return GetAddress() != _other.GetAddress();
			}
			template<typename Class>
			bool operator==(Res(Class::* ptr)(Params...))
			{
				return GetAddress() == (void*&)ptr;
			}
			template<typename Class>
			bool operator!=(Res(Class::* ptr)(Params...))
			{
				return GetAddress() != (void*&)ptr;
			}
		};
	}

}
