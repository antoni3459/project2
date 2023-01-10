#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>
#include <map>

class BaseMenu;

class Window:public Object
{
protected:
	float height = 1080;
	const char* title = "Flappy Bird";
	float width = 1920;

	bool eventIfNotFocus = false;
	sf::RenderWindow* window = nullptr;
	std::map<const char*, BaseMenu*> menu = std::map<const char*, BaseMenu*>();
	bool eventfocus;
public:
	Window() = default;
	Window(const float _widht, const float _height, const char* _title);
	Window(const Window& _copy) = delete;
	virtual ~Window();

private:
	void Update();
public:
	void Open();
	void Close();
	bool IsOpen()const;
	bool HasFocus()const;
	void SetFrameLimit(const int _frame);
	void Draw(sf::Drawable* _drawable);
	sf::RenderWindow* Renderer()const;
	int Width();
	int Height();
protected:
	void CloseAllMenu();
	void OpenMenu(const char* _name);
	void RegisterMenu(const char* _name, BaseMenu* _menu);
	virtual void InitMenus();
	virtual void OnDraw() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRecieveEvent(sf::Event& _event);
};

