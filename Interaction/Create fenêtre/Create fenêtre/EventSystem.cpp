#include "EventSystem.h"
#include "Button.h"
#include "Event.h"
#include "Rect.h"

void EventSystem::Register(Button* _button)
{
	button.push_back(_button);
}

void EventSystem::UnRegister(Button* _button)
{
	const size_t _size = button.size();
	for (size_t i = 0; i < _size;i++)
	{
		if (button[i] == _button)
		{
			button.erase(button.begin() + i);
			break;
		}
	}
}

void EventSystem::Update()
{
	const size_t _size = button.size();
	for (size_t i = 0;i < _size;i++)
	{
		if (button[i]->GetRect()->Contains(Event::mousePositionX, Event::mousePositionY))
			button[i]->OnClick();
	}
}

void EventSystem::Clear()
{
	const size_t _size = button.size();
	for (size_t i = 0;i < _size;i++)
		delete button[i];
	button.clear();
}

void EventSystem::OnDestroy()
{
	Clear();
}
