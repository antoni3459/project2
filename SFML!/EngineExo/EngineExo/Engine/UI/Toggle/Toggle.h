#pragma once
#include "../Element/UIElement.h"
#include "../Interface/IPointerClickHandler.h"

#define TOGGLE_VALID_NAME "toggle_valid"
#define TOGGLE_INVALID_NAME "toggle_invalid"


namespace Engine::UI
{
	class Toggle:public UIElement,public IPointerClickHandler
	{
		DECLARE_CLASS_INFO(Toggle,UIElement)

	private:
		bool status = false;
		sf::Texture* toggleFalseTexture = nullptr;
		sf::Texture* toggleTrueTexture = nullptr;

	public:
		Toggle();
		Toggle(bool _status);

	public:
		void SetStatus(bool _status);
		void OnPointerClick(const sf::Event& _event)override;
		void OnPointerUnClick()override {};
	};
};

