#include "Toggle.h"
#include "../../../Utils/DebugMacro.h"
#include "../../../Event/Delegate/Delegate.h"
#include "../../../Window/Engine/EngineWidnow.h"

Engine::UI::Toggle::Toggle(Window::EngineWindow* _owner) : super(_owner)
{
	toggle = new sf::RectangleShape(sf::Vector2f(50, 50));
	toggle->setFillColor(sf::Color::Red);
	OnClicked.SetDynamic(this, &Toggle::Check);
}

Engine::UI::Toggle::~Toggle()
{
	Free();
}

Engine::UI::Toggle::Toggle(const Toggle& _copy) : super(_copy) { }

void Engine::UI::Toggle::Free()
{
	delete toggle;
	toggle = nullptr;
}

void Engine::UI::Toggle::Check()
{
	if (timeBeforeTouchButton.getElapsedTime().asSeconds() >= CAN_PUSH)
	{
		timeBeforeTouchButton.restart();
		switch (isPressed)
		{
		case true:
		{
			toggle->setFillColor(sf::Color::Red);
			isPressed = false;
			break;
		}
		case false:
		{
			toggle->setFillColor(sf::Color::Green);
			isPressed = true;
			break;
		}
		default:
			break;
		}
	}
}

void Engine::UI::Toggle::SetPosition(sf::Vector2f _position)
{
	checkLow((toggle != nullptr), "[Toggle] => toggle is nullptr")
	toggle->setPosition(_position);
}

sf::Vector2f Engine::UI::Toggle::Position() const
{
	check((toggle != nullptr), "[Toggle] => toggle is nullptr", sf::Vector2f(0, 0))
	toggle->getPosition();
}

void Engine::UI::Toggle::SetScale(sf::Vector2f _scale)
{
	checkLow((toggle != nullptr), "[Toggle] => toggle is nullptr")
		toggle->setScale(_scale);
}

sf::Vector2f Engine::UI::Toggle::Scale() const
{
	check((toggle != nullptr), "[Toggle] => toggle is nullptr", sf::Vector2f(0, 0))
		toggle->getScale();
}

void Engine::UI::Toggle::SetOrigin(sf::Vector2f _origin)
{
	checkLow((toggle != nullptr), "[Toggle] => toggle is nullptr")
	toggle->setOrigin(_origin);
}

sf::Vector2f Engine::UI::Toggle::Origin() const
{
	check((toggle != nullptr), "[Toggle] => toggle is nullptr", sf::Vector2f(0, 0))
		toggle->getOrigin();
}

sf::FloatRect Engine::UI::Toggle::GlobalBounds() const
{
	check((toggle != nullptr), "[Toggle] => toggle is nullptr", sf::FloatRect(0, 0, 0, 0))
	toggle->getGlobalBounds();
}

void Engine::UI::Toggle::Draw()
{
	if (toggle == nullptr) return;
	Engine::Window::EngineWindow::Instance()->Draw(toggle);
}

void Engine::UI::Toggle::OnUpdate()
{
	//if (!isActive) return;
	const sf::Vector2i _mousePosition = sf::Mouse::getPosition(*owner->Renderer());
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && toggle->getGlobalBounds().contains(sf::Vector2f(_mousePosition.x, _mousePosition.y)))
	{
		OnClicked.Invoke();
	}
}

