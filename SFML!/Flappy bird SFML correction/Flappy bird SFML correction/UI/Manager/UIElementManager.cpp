#include "UIElementManager.h"
#include "../FB_UIElement.h"

void UIElementManager::Register(FB_UIElement* _element)
{
	element.push_back(_element);
}

void UIElementManager::UnRegister(FB_UIElement* _element)
{
	const size_t size = element.size();
	for (size_t i = 0; i < size;i++)
	{
		if (element[i] == _element)
		{
			element.erase(element.begin() + i);
			break;
		}
	}
}

void UIElementManager::Update()
{
	const size_t _size = element.size();
	for (size_t i = 0;i < _size;i++)
	{
		element[i]->OnUpdate();
	}
}

void UIElementManager::OnDestroy()
{
	const size_t _size = element.size();
	for (size_t i = 0; i < _size; i++)
		delete element[i];
	element.clear();
}


