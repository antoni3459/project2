#pragma once
#include "../Object/Object.h"
#include "../Event/Action/Action.h"

namespace Engine
{
	class Selection : public Object
	{
		DECLARE_CLASS_INFO(Selection, Object)
	private:
		static inline Object* selected = nullptr;
	public:
		static inline Action<Object*> OnSelectionGhanged = nullptr;

	public:
		static void SetSelection(Object* _obj);
		static Object* GetSelected();
	};
}

