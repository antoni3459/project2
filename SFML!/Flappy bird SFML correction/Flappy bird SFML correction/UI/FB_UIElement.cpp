#include "FB_UIElement.h"
#include "Manager/UIElementManager.h"

FB_UIElement::FB_UIElement(Window* _owner)
{
	owner = _owner;
	UIElementManager::Instance()->Register(this);
}

FB_UIElement::FB_UIElement(const FB_UIElement& _copy)
{
	owner = _copy.owner;
	isActive = _copy.isActive;
}

FB_UIElement::~FB_UIElement()
{
	UIElementManager::Instance()->UnRegister(this);
}

void FB_UIElement::OnUpdate()
{
}

void FB_UIElement::SetActive(const bool _status)
{
	isActive = _status;
}
