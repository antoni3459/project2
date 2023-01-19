#include "Window.h"
#include "Window.h"
#include "Event.h"
#include "Time.h"

Window::Window(const float _width, const float _height, const char* _title)
{
	width = _width;
	height = _height;
	title = _title;
}

Window::~Window()
{
	Close();
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
			//TODO event if not focus ?
			if (!window->hasFocus() && !eventIfNotFocus)continue;
			Event::currentEvent = &_event;
			OnReceiveEvent(_event);
			break;
		}
		OnUpdate();
		window->clear();
		OnDraw();
		window->display();
	}
}

void Window::Open()
{
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

void Window::OnReceiveEvent(sf::Event& _event)
{
	Event::currentEvent = &_event;
	if (_event.type == sf::Event::Closed)
		Close();
}
