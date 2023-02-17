#include "ATest.h"
#include "../Window/Engine/EngineWindow.h"
#include "../UI/Slider/Slider.h"
#include "../UI/Toggle/Toggle.h"
#include "../UI/TextField/TextField.h"
#include "../PrimaryType/Vector/Vector2.h"

Engine::ATest::ATest() :super()
{
}

Engine::ATest::ATest(const ATest& _copy) :super(_copy)
{
	toggle = _copy.toggle;
	slider = _copy.slider;
	textField = _copy.textField;
}

void Engine::ATest::Open()
{
	if (isClick)
	{
		SetToggle();
		SetSlider();
		SetTextField();
	}
	Draw();
	isClick = true;
}

void Engine::ATest::Draw()
{
	UI::Toggle* toggle = new UI::Toggle(false);
	toggle->SetPosition(PrimaryType::Vector2(1540, 150));
	
	UI::Slider* slider = new UI::Slider(0.0f, 100.0f, 40.0f);
	slider->SetPosition(PrimaryType::Vector2(1510, 250));
	
	UI::TextField* textField = new UI::TextField("", "text", PrimaryType::Vector2(90, 90));
	textField->SetPosition(PrimaryType::Vector2(1530, 350));
}

void Engine::ATest::SetToggle()
{
	UI::Toggle* toggleP = nullptr;
	toggle = toggleP->GetStatus();
}

void Engine::ATest::SetSlider()
{
	UI::Slider* sliderP = nullptr;
	slider = sliderP->GetCurrentValue();
}

void Engine::ATest::SetTextField()
{
	UI::TextField* textFieldP = nullptr;
	textField = textFieldP->GetInputText();
}
