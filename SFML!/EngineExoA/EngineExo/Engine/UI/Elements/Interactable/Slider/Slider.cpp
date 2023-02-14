#include "Slider.h"
#include "../../../Utils/DebugMacro.h"
#include "../../../Window/Engine/EngineWidnow.h"

Engine::UI::Slider::Slider(Window::EngineWindow* _owner) : super(_owner)
{
	line = new sf::RectangleShape(sf::Vector2f(100.0f,2.0f));

	circle = new sf::CircleShape(5.0f);
	circle->setPosition(line->getPosition().x + 45.0f, circle->getPosition().y - 4.0f);

	percentage = new Label(_owner, "D:/ThibaudD/EngineExo/Fonts/Gabato.ttf");
	percentage->SetScale(sf::Vector2f(0.5f, 0.5f));
	percentage->SetPosition(sf::Vector2f(line->getPosition().x + line->getGlobalBounds().width + 15.0f, line->getPosition().y));
	percentageFloat = (circle->getPosition().x / circle->getScale().x + 5.0f) - (line->getPosition().x / line->getScale().x);
	percentage->SetString(std::to_string(percentageFloat).c_str());

	OnClicked.SetDynamic(this, &Slider::Move);
}
Engine::UI::Slider::~Slider()
{
	Free();
}

Engine::UI::Slider::Slider(const Slider& _copy) : super(_copy) { }

void Engine::UI::Slider::Free()
{
	delete line;
	line = nullptr;
	delete circle;
	circle = nullptr;
}

void Engine::UI::Slider::Move()
{
	const sf::Vector2i _mousePosition = sf::Mouse::getPosition(*owner->Renderer());
	circle->setPosition(sf::Vector2f(_mousePosition.x - 5.0f * circle->getScale().x, Position().y));
	float _lineStart = line->getPosition().x;
	float _lineEnd = line->getPosition().x + line->getGlobalBounds().width;
	if (Position().x +  5.0f * circle->getScale().x > _lineEnd)
	{
		circle->setPosition(sf::Vector2f(_lineEnd - 5.0f * circle->getScale().x, Position().y));
	}
	else if (Position().x + 5.0f * circle->getScale().x < _lineStart)
	{
		circle->setPosition(sf::Vector2f(_lineStart - 5.0f * circle->getScale().x, Position().y));
	}
	percentageFloat = (circle->getPosition().x / circle->getScale().x + 5.0f) - (line->getPosition().x / line->getScale().x);
	percentage->SetString(std::to_string(percentageFloat).c_str());
}


void Engine::UI::Slider::SetPosition(sf::Vector2f _position)
{
	checkLow((circle != nullptr && line != nullptr), "[Slider] => circle or line is nullptr")
	float _diff = circle->getPosition().x - line->getPosition().x;
	line->setPosition(_position);
	circle->setPosition(_position + sf::Vector2f(_diff, -4.0f * circle->getScale().y));
	percentage->SetPosition(sf::Vector2f(line->getPosition().x + line->getGlobalBounds().width + 15.0f * line->getScale().x, line->getPosition().y));
}

sf::Vector2f Engine::UI::Slider::Position() const
{
	check((circle != nullptr), "[Slider] => circle is nullptr", sf::Vector2f(0, 0))
	circle->getPosition();
}

void Engine::UI::Slider::SetScale(sf::Vector2f _scale)
{
	checkLow((circle != nullptr && line != nullptr), "[Slider] => circle or line is nullptr")
	float _diff = circle->getPosition().x - line->getPosition().x;
	line->setScale(_scale);
	circle->setScale(_scale);
	percentage->SetScale(sf::Vector2f(_scale.x / 2, _scale.y / 2));
	circle->setPosition(sf::Vector2f(line->getPosition().x + _diff * line->getScale().x, circle->getPosition().y - 4.0f * circle->getScale().y));
	percentage->SetPosition(sf::Vector2f(line->getPosition().x + line->getGlobalBounds().width + 15.0f * percentage->Scale().x, line->getPosition().y));
}

sf::Vector2f Engine::UI::Slider::Scale() const
{
	check((circle != nullptr), "[Slider] => circle is nullptr", sf::Vector2f(0, 0))
	circle->getScale();
}

void Engine::UI::Slider::SetOrigin(sf::Vector2f _origin)
{
	checkLow((circle != nullptr && line != nullptr), "[Slider] => circle or line is nullptr")
	line->setOrigin(_origin);
	circle->setOrigin(_origin);
	percentage->SetOrigin(_origin);
}

sf::Vector2f Engine::UI::Slider::Origin() const
{
	check((circle != nullptr), "[Slider] => circle is nullptr", sf::Vector2f(0, 0))
	circle->getOrigin();
}

sf::FloatRect Engine::UI::Slider::GlobalBounds() const
{
	check((circle != nullptr), "[Slider] => circle is nullptr", sf::FloatRect(0, 0, 0, 0))
	circle->getGlobalBounds();
}

void Engine::UI::Slider::Draw()
{
	if (circle == nullptr || line == nullptr) return;
	Engine::Window::EngineWindow::Instance()->Draw(line);
	Engine::Window::EngineWindow::Instance()->Draw(circle);
	percentage->Draw();
}

void Engine::UI::Slider::OnUpdate()
{
	//if (!isActive) return;
	const sf::Vector2i _mousePosition = sf::Mouse::getPosition(*owner->Renderer());
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && circle->getGlobalBounds().contains(sf::Vector2f(_mousePosition.x, _mousePosition.y)))
	{
		OnClicked.Invoke();
	}
}
