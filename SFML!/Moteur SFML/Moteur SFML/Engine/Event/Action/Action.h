#pragma once
#include <vector>
#include "../../Utils/DebugMacro.h"
#include "../Delegate/Delegate.h"
#include "../../Object/Object.h"



namespace Engine::Event
{
    template<typename Res, typename... Params>
    class ActionInternal : public Object
    {
        DECLARE_CLASS_INFO(ActionInternal, Object)

    private:
        std::vector<Delegate<Res, Params...>> delegates = std::vector<Delegate<Res, Params...>>();
    public:
        ActionInternal(nullptr_t)
        {
            delegates.clear();
        }
        template<typename Class>
        ActionInternal(Class* _instance, Res(Class::* ptr)(Params...))
        {
            checkBaseOf(Object, Class)
                delegates.push_back(Delegate<Res, Params...>(_instance, ptr));
        }
    public:
        template<typename Class>
        void AddDynamic(Class* _instance, Res(Class::* ptr)(Params...))
        {
            checkBaseOf(Object, Class)
                delegates.push_back(Delegate<Res, Params...>(_instance, ptr));
        }
        template<typename Class>
        void RemoveDynamic(Class* _instance, Res(Class::* ptr)(Params...))
        {
            checkBaseOf(Object, Class)
                std::vector<Delegate<Res, Params...>>::iterator it = delegates.begin();
            for (, it != delegates.end(); it++)
            {
                if (*it.GetAdress() == (void*&)ptr && *it.Instance() == _instance)
                {
                    delegates.erase(it);
                    break;
                }
            }
        }
        Res Invoke(Params.._params)
        {
            if constexpr (std::is_base_of_v<Res, void>)
            {
                for (Delegate<Res, Params...> _delegate : delegates)
                    _delegate.Invoke(_params...)
                    return Res();
            }
            else
            {
                Res result = Res();
                for (Delegate<Res, Params...> _delegate : delegates)
                    _result = _delegate.Invoke(_params...)
                    return result;
            }
        }

    public:
        Action& operator=(const Action& _other)
        {
            delegates = _other.delegates;
            return *this;
        }
        ActionInternal& operator=(nullptr_t)
        {
            delegtaes.clear();
            return *this;
        }
        Res operator()(Params... _params)
        {
            return Invoke(_params...);
        }
    };
}

template<typename... Params>
using Action = Engine::Event::ActionInternal<void, Params...>;

template<typename T, typename... Params>
using Func = Engine::Event::ActionInternal<T, Params...>;

template<typename... Params>
using Predicate = Engine::Event::ActionInternal<bool, Params...>;