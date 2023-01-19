#include "UIElement.h"
#include "../Utils/Debug/Debug.h"
#include "../Window/Window.h"

Core::UI::UIElement::UIElement(Window* _owner)
{
	owner = _owner;
	//TODO Register to manager
}

Core::UI::UIElement::UIElement(const UIElement& _copy)
{
	drawable=_copy.drawable;
	owner = _copy.owner;
	//TODO Register to manager
}

Core::UI::UIElement::~UIElement()
{
	//TODO Register to manager
	delete drawable;
	drawable = nullptr;
}

void Core::UI::UIElement::SetActive(bool _status)
{
	isActive = _status;

}

bool Core::UI::UIElement::IsActive() const
{
	return isActive;
}

bool Core::UI::UIElement::IsValid() const
{
	return drawable != nullptr && owner != nullptr;
}

void Core::UI::UIElement::Draw()
{
	if (!isActive)return;
	checkLow(IsValid(), "[UIElement] => owner or drawable is not valid !");
	owner->Draw(drawable);
}

void Core::UI::UIElement::OnUpdate() {}

