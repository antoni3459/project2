#pragma once
#include "../UI_Elements.h"
#include "../../Event/Delegate/Delegate.h"

namespace Engine::UI
{
	class Interactable : public UI_Elements
	{
		DECLARE_CLASS_INFO(Interactable, UI_Elements)
#pragma region f/p
	protected:
		Event::Delegate<void> OnClicked = nullptr;
#pragma endregion
#pragma region constructor
	public:
		Interactable() = default;
		Interactable(Window::EngineWindow* _owner);
#pragma endregion
	};
}

 