#pragma once
#include "../../Utils/Singleton/Singleton.h"
#include "../../Utils/Debug/Debug.h"

#include <map>
#include <format>
#include <ranges>

namespace Core
{
    namespace Manager
    {
        template<typename Class, typename Item>
        class BaseManager :public Utils::Singleton<Class>
        {
            DECLARE_CLASS_INFO(BaseManager, Utils::Singleton<Class>)

        protected:
            std::map<std::string, Item*> items = std::map<std::string, Item*>();

        public:
            virtual void Init() = 0;
            virtual Item* Load(const char* _name);

        protected:
            void OnDestroy()override;

        };

        template<typename Class, typename Item>
        inline Item* BaseManager<Class, Item>::Load(const char* _name)
        {    
            Check(items.contains(_name), std::format("[BaseManager] => doesn't found key: {}", _name), nullptr)
                return items[_name];
        }

        template<typename Class, typename Item>
        inline void BaseManager<Class, Item>::OnDestroy()
        {
            for (Item*& _item : items | std::ranges::views::values)
            {
                delete _item;
                _item = nullptr;
            }
            items.clear();
        }
    }
}

