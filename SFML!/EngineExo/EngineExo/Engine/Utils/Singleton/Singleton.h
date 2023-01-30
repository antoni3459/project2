#pragma once
#include "../../Object/Object.h"

namespace Engine::Utils
{
	template<typename T>
	class Singleton : public Object
	{
		DECLARE_CLASS_INFO(Singleton<T>, Object)

	private:
		static inline T* instance = nullptr;

	public:
		Singleton() = default;
		Singleton(const Singleton&) = delete;
		~Singleton() override
		{
			OnDestroy();
		}

	public:
		static T* Instance()
		{
			if (instance == nullptr) instance = new T();
			return instance;
		}
		void Destroy()
		{
			delete instance;
			instance = nullptr;
		}
		virtual void OnDestroy(){}


	};
}