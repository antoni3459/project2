#pragma once
#include "singleton.h"
#include <vector>

class Button;

class EventSystem :public Singleton<EventSystem>
{
private:
	std::vector<Button*> button = std::vector<Button*>();

public:
	void Register(Button* _button);
	void UnRegister(Button* _button);
	void Update();
	void Clear();

public:
	void OnDestroy()override;
};