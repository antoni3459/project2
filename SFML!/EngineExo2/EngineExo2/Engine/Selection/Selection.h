#pragma once
#include "../Event/Action/ActionInternal.h"
#include "../Object/Object.h"

namespace Engine
{
    class Selection : public Object
    {
        DECLARE_CLASS_INFO(Selection, Object)
#pragma region f/p
    private:
        static inline Object* selected = nullptr;
    public:
        static inline Action<Object*> OnSelectionChanged = nullptr;
#pragma endregion f/p
#pragma region methods
    public:
        static void SetSelection(Object* _obj);
        static Object* GetSelected();
#pragma endregion methods
    };
}
