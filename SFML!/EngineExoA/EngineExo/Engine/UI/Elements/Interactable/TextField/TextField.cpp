#include "TextField.h"
#include "../../../Window/Engine/EngineWidnow.h"

Engine::UI::TextField::TextField(Window::EngineWindow* _owner, const char* _path) : super(_owner)
{
	text = new Label(_owner, _path);
	rect = new sf::RectangleShape(sf::Vector2f(500, 40));
	rect->setFillColor(sf::Color::White);
	text->SetColor(sf::Color::Black);
	text->SetString(textStr);
	OnClicked.SetDynamic(this, &TextField::SetOnWriteMode);
}

Engine::UI::TextField::TextField(const TextField& _copy) : super(_copy) { }



void Engine::UI::TextField::Free()
{
	delete text;
	text = nullptr;
}

void Engine::UI::TextField::Delete()
{
	if (textStr.Length() != 0)
	{
		textStr = textStr.SubString(0, textStr.Length() - 1);
		text->SetString(textStr);
	}
}

void Engine::UI::TextField::Write(sf::Event::TextEvent _c)
{
	char _char = static_cast<char>(_c.unicode);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		Delete();
	}
	else
	{
		textStr.Append(_char);
		text->SetString(textStr);
	}
}

void Engine::UI::TextField::SetOnWriteMode()
{
	const sf::Vector2i _mousePosition = sf::Mouse::getPosition(*owner->Renderer());
	if (timeBeforeClick.getElapsedTime().asSeconds() >= CAN_PUSH)
	{
		timeBeforeClick.restart();
		switch (rect->getGlobalBounds().contains(sf::Vector2f(_mousePosition.x, _mousePosition.y)))
		{
		case true:
		{
			if (!onWriteMode)
			{
				onWriteMode = true;
			}
			break;
		}
		case false:
		{
			if (onWriteMode)
			{
				onWriteMode = false;
			}
			break;
		}
		default:
			break;
		}
	}
}

void Engine::UI::TextField::SetPosition(sf::Vector2f _position)
{
	checkLow((text != nullptr && rect != nullptr), "[TextField] => text is nullptr")
		text->SetPosition(_position);
	rect->setPosition(_position);
}

sf::Vector2f Engine::UI::TextField::Position() const
{
	check((text != nullptr && rect != nullptr), "[TextField] => text is nullptr", sf::Vector2f(0, 0))
		rect->getPosition();
}

void Engine::UI::TextField::SetScale(sf::Vector2f _scale)
{
	checkLow((text != nullptr && rect != nullptr), "[TextField] => text is nullptr")
		text->SetScale(_scale);
	rect->setScale(_scale);
}

sf::Vector2f Engine::UI::TextField::Scale() const
{
	check((text != nullptr && rect != nullptr), "[TextField] => text is nullptr", sf::Vector2f(0, 0))
		rect->getScale();
}

void Engine::UI::TextField::SetOrigin(sf::Vector2f _origin)
{
	checkLow((text != nullptr && rect != nullptr), "[TextField] => text is nullptr")
		text->SetOrigin(_origin);
	rect->setOrigin(_origin);
}

sf::Vector2f Engine::UI::TextField::Origin() const
{
	check((text != nullptr && rect != nullptr), "[TextField] => text is nullptr", sf::Vector2f(0, 0))
	rect->getOrigin();
}

sf::FloatRect Engine::UI::TextField::GlobalBounds() const
{
	check((text != nullptr && rect != nullptr), "[TextField] => text is nullptr", sf::FloatRect(0,0,0,0))
	rect->getGlobalBounds();
}

void Engine::UI::TextField::Draw()
{
	if (text == nullptr && rect != nullptr) return;
	Engine::Window::EngineWindow::Instance()->Draw(rect);
	text->Draw();
}

void Engine::UI::TextField::OnUpdate()
{
	owner->Renderer()->setKeyRepeatEnabled(false);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		OnClicked.Invoke();
	}
	if (onWriteMode && (timeBeforeType.getElapsedTime().asSeconds() >= CAN_TYPE))
	{
        timeBeforeType.restart();
		if (owner->CurrentEvent().type == sf::Event::TextEntered)
		{
			Write(owner->CurrentEvent().text);
		}
	}
}
