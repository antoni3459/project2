#include "ATest.h"
#include "../Window/Engine/EngineWindow.h"
#include "../UI/Slider/Slider.h"
#include "../UI/Toggle/Toggle.h"
#include "../UI/TextField/TextField.h"
#include "../UI/Label/Label.h"
#include "../PrimaryType/Vector/Vector2.h"
#include "../Manager/EventSystem/EventSystem.h"

#include <string>
#include <format>

Engine::ATest::ATest() :super()
{
	engineWindow = new Engine::Window::EngineWindow();
}

Engine::ATest::ATest(const ATest& _copy) :super(_copy)
{
	toggle=_copy.toggle;
	textField = _copy.textField;
	isClick = _copy.isClick;
	engineWindow = _copy.engineWindow;
}

void Engine::ATest::OpenTest()
{
	Draw();
}

void Engine::ATest::Draw()
{
	UI::Toggle* toggle = new UI::Toggle(false);
	toggle->SetPosition(PrimaryType::Vector2(1540, 150));

	UI::TextField* textField = new UI::TextField("", "text", PrimaryType::Vector2(90, 90));
	textField->SetPosition(PrimaryType::Vector2(1530, 350));

	slider = new UI::Slider(0.0f, 100.0f, 40.0f);
	slider->SetPosition(PrimaryType::Vector2(1510, 250));
}

void Engine::ATest::SetToggle()
{
	UI::Toggle* toggleP = nullptr;
	toggle = toggleP->GetStatus();
}

void Engine::ATest::SetSlider()
{
	UI::Slider* sliderP = nullptr;
	sliderInt = sliderP->GetCurrentValue();
}

void Engine::ATest::SetTextField()
{
	UI::TextField* textFieldP = nullptr;
	textField = textFieldP->GetInputText();
}


