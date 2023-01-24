#pragma once
#include "../../Object/Object.h"

namespace Engine::Uitls
{
    template<typename T>
    class Singleton :
        public Object
    {
        DECLARE_CLASS_INFO(Singleton, Object)

    private:
        static T* instance = nullptr;

    public:
        Singleton() = default;
        Singleton(const Singleton&) = delete;
        ~Singleton()override
        {
            OnDestroy();
        }

    public:
        static T* Instance()
        {
            if (instance == nullptr)instance = new T();
            return instance;
        }

        void Destroy()
        {
            delete instance;
            instance = nullptr;
        }
        virtual void OnDetroy() {}
    };
}

