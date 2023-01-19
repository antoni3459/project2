#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>
#include <map>

namespace Core
{
	class Window :public Object
	{
		DECLARE_CLASS_INFO(Window, Object)

	protected:
		int width = 900;
		int height = 800;
		const char* title = "Default Window Name";
		sf::RenderWindow* render = nullptr;
		sf::Event currentEvent = sf::Event();
		sf::Clock deltaClock = sf::Clock();
		std::map < const char*, class BaseMenu*> menus= std::map < const char*, class BaseMenu*>();
	public:
		Window() = delete;
		Window(int _width, int _height, const char* _title);
		Window(const Window&) = delete;
		~Window()override;

	public:
		void Open();
		void Close();
		int Width()const;
		int Height()const;
		sf::RenderWindow* Render()const;
		void Draw(const sf::Drawable* _drawable)const;
		void OpenMenu(const char* _menu);
	protected:
		void CloseAllMenu();
		void RegisterMenu(const char* _name, BaseMenu* _menu);
		void OnDraw();
		void OnUpdate();
		void OnReceiveEvent(const sf::Event& _event);

	private:
		void Update();
	};
}

