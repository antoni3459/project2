#pragma once
#include "../../Singleton/Singleton.h"
#include <vector>

class FB_UIElement;

class UIElementManager : public Singleton< UIElementManager>
{
	std::vector < FB_UIElement*> element = std::vector < FB_UIElement*>();

public:
	UIElementManager() = default;

public:
	void Register(FB_UIElement* _element);
	void UnRegister(FB_UIElement* _element);
	void Update();

public:
	virtual void OnDestroy()override;
};

