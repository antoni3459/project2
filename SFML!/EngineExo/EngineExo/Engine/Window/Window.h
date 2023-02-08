#pragma once
#include <SFML/Graphics.hpp>
#include "../Utils/Singleton/Singleton.h"
#include "../PrimaryType/FString/String.h"
#include "../PrimaryType/Integer/Integer.h"
#include "../Utils/DebugMacro.h"
#include "../PrimaryType/Boolean/Boolean.h"

namespace Engine::Window
{
	template<typename T>
	class Window : public Engine::Utils::Singleton<T>
	{
		DECLARE_CLASS_INFO(Window, Engine::Utils::Singleton<T>)

#pragma region f/p
	protected:
		sf::RenderWindow* render = nullptr;
		PrimaryType::String name = "";
		PrimaryType::Integer width = 0;
		PrimaryType::Integer height = 0;
		PrimaryType::Boolean hasFocus = false;
		sf::Event currentevent = sf::Event();
#pragma endregion f/p

#pragma region constructor/destructor
	public:
		Window() = delete;
		Window(const char* _name, const int _width = 800, const int _height = 600)
		{
			name = _name;
			width = _width;
			height = _height;
		}
		Window(const Window&) = delete;
#pragma endregion constructor/destructor

#pragma region method
	private:
		void Update()
		{
			while (render->isOpen())
			{
				while (render->pollEvent(currentevent))
				{
					if (currentevent.type == sf::Event::Closed)
						Close();
					if (currentevent.type == sf::Event::LostFocus || currentevent.type == sf::Event::GainedFocus)
						SetFocus(currentevent.type);
					if (hasFocus)
						OnReciveEvent(currentevent);
				}
				OnUpdate();
			}

		}


		void SetFocus(const sf::Event::EventType& _eventType)
		{
			hasFocus = _eventType == sf::Event::LostFocus ? false : true;
			LOG_FORMAT("[Engine] Focus: {} ", hasFocus.ToString().ToCstr())
		}

	public:
		virtual void Open()
		{
			render = new sf::RenderWindow(sf::VideoMode(width, height), name.ToCstr());
			SetFrameLimit(60);
			Update();
		}
		void Close()
		{
			render->close();
		}
		PrimaryType::Boolean IsOpen()const
		{
			return render->isOpen();
		}
		PrimaryType::Boolean HasFocus()const
		{
			return hasFocus;
		}
		void SetFrameLimit(int _frame)const
		{
			render->setFramerateLimit(_frame);
		}
		void Draw(sf::Drawable* _drawable)const
		{
			render->draw(*_drawable);
		}

	protected:
		virtual void OnUpdate()
		{

		}
		virtual void OnDraw() {}
		virtual void OnClear() const {}
		virtual void OnReciveEvent(const sf::Event& _event) const {}
		void Clear()const
		{
			render->clear();
			OnClear();
		}
		void Display()const
		{
			render->display();
		}
#pragma endregion method

#pragma region override
	public:
		PrimaryType::String ToString()const override
		{
			PrimaryType::String _result = "==========Window Settings==========\n";
			_result += PrimaryType::String("Name: ");
			_result += name;
			_result += "\nWidth: ";
			_result += width.ToString();
			_result += "\nheight: ";
			_result += height.ToString();
			_result += "\n====================================\n";
			return _result;
		}
#pragma endregion override

	};

}