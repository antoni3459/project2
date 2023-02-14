#pragma once 
#include "../Window.h"
#include "../../UI/Label/Label.h"
#include "../../UI/Interactable/Slider/Slider.h"
#include "../../UI//Interactable/Toggle/Toggle.h"
#include "../../UI/Interactable/TextField/TextField.h"

namespace Engine::Window
{
	class EngineWindow : public Window<EngineWindow>
	{
		DECLARE_CLASS_INFO(EngineWindow, Window<EngineWindow>)
	private:
		sf::Clock clock = sf::Clock();
		Engine::UI::Label* text = new Engine::UI::Label(this, "D:/ThibaudD/EngineExo/Fonts/Gabato.ttf");
		Engine::UI::Slider* slider = new Engine::UI::Slider(this);
		Engine::UI::Toggle* toggle = new Engine::UI::Toggle(this);
		Engine::UI::TextField* textField = new Engine::UI::TextField(this,"D:/ThibaudD/EngineExo/Fonts/Gabato.ttf");

	public:
		EngineWindow();
	public:
		void Open() override;
		void OnUpdate() override;
		void OnClear() const override;
		void OnRecieveEvent(const sf::Event& _event) const override;
	};
}