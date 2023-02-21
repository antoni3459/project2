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

Engine::ATest::ATest(const ATest& _copy) :super(_copy)
{
	toggle=_copy.toggle;
	textField = _copy.textField;
	isClick = _copy.isClick;
}

void Engine::ATest::OpenTest()
{
	Draw();
}

void Engine::ATest::Draw()
{

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



