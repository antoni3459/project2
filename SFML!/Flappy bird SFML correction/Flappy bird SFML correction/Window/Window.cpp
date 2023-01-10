#include "Window.h"
#include "../Event/Event.h"
#include "../Time/Time.h"
#include "Menu/BaseMenu.h"
#include <format>
#include "../UI/Manager/UIElementManager.h"

Window::Window(const float _width, const float _height, const char* _title)
{
	width = _width;
	height = _height;
	title = _title;
}

Window::~Window()
{
	Close();
	for (std::pair<const char*, BaseMenu*> _pair : menu)
	{
		delete _pair.second;
	}
	menu.clear();
	delete window;
}

void Window::Update()
{
	sf::Event _event = sf::Event();
	sf::Clock _clock = sf::Clock();
	while (window->isOpen())
	{
		Time::deltaTime = _clock.restart().asSeconds();
		while (window->pollEvent(_event))
		{
			if (!window->hasFocus() && !eventIfNotFocus)continue;
			Event::currentEvent = &_event;
			OnRecieveEvent(_event);
			break;
		}
		UIElementManager::Instance()->Update();
		OnUpdate();
		window->clear();
		OnDraw();
		window->display();
	}
}
void Window::Open()
{
	InitMenus();
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	Update();
}

void Window::Close()
{
	if (!window->isOpen())return;
	window->close();
}

bool Window::IsOpen() const
{
	return window->isOpen();
}

bool Window::HasFocus() const
{
	return window->hasFocus();
}

void Window::SetFrameLimit(const int _frame)
{
	window->setFramerateLimit(_frame);
}

void Window::Draw(sf::Drawable* _drawable)
{
	window->draw(*_drawable);
}

void Window::OnRecieveEvent(sf::Event& _event)
{
	Event::currentEvent = &_event;
	if (_event.type == sf::Event::Closed)
		Close();
}

sf::RenderWindow* Window::Renderer() const
{
	return window;
}

int Window::Width()
{
	return width;
}

int Window::Height()
{
	return height;
}

void Window::CloseAllMenu()
{
	for (std::pair<const char*, BaseMenu*> _menu : menu)
		_menu.second->Close();
}

void Window::OpenMenu(const char* _name)
{
	CloseAllMenu();
	if (!menu.contains(_name))
	{
		throw std::exception(std::format("Menu: {} doaesn't exist", _name).c_str());
	}
	menu[_name]->Open();
}

void Window::RegisterMenu(const char* _name, BaseMenu* _menu)
{
	menu.insert(std::pair(_name, _menu));
}

void Window::InitMenus()
{
}
