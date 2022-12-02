#pragma once
#include "ParamatereInfo.h"
#include <exception>
#include <vector> 

namespace Core
{
	class Object;
#pragma warning(disable:4251)
	class BaseMethodeInfo
	{
	public:
		virtual ~BaseMethodeInfo() = default;
	};

	template<typename Result, typename Class, typename... Param>
	class  MethodInfo :public BaseMethodeInfo
	{
#pragma region f/p
	private:
		std::vector<ParameterInfo> params = std::vector<ParameterInfo>();
		typedef Result(Object::* Function)(Param...);
		Function functionPtr = nullptr;
		Object* instance = nullptr;
#pragma endregion f/p
#pragma region constructor

	public:
		MethodInfo() = default;
		MethodInfo(Class* _instance, Result(Class::* ptr)(Param...))
		{
			instance = _instance;
			functionPtr = reinterpret_cast<Function>(ptr);
		}
#pragma endregion constructor
#pragma region method

	public:
		std::vector<ParameterInfo> Params()const
		{
			return params;
		}

		Result Invoke(Param... _params)
		{
			if (functionPtr == nullptr)
				throw std::exception("function is null !");
			if (instance == nullptr)
				throw std::exception("instance is null !");
			return (instance->*functionPtr)(_params...);
		}

		void* GetAddress()
		{
			return (void*&)functionPtr;
		}
#pragma endregion method

	};
}
