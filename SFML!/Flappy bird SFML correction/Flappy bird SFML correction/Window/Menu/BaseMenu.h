#pragma once
#include "../../Object/Object.h"
#include <vector>

class BaseMenu : public Object
{
protected:
	std::vector<class FB_UIElement*> elements = std::vector<class FB_UIElement*>();
	bool isOpen = false;
	class Window* owner = nullptr;

public:
	BaseMenu(Window* _owner);
	virtual ~BaseMenu()override;

public: 
	void Open();
	void Close();
	void SetActive(const bool _status);
	virtual void Draw();
};

