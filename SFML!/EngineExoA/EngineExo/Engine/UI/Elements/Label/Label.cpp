#include "Label.h"
#include "../../Utils/DebugMacro.h"
#include "../../Window/Window.h"
#include "../../Window/Engine/EngineWidnow.h"

Engine::UI::Label::Label(Window::EngineWindow* _owner, const char* _path) : super(_owner)
{
	text = new sf::Text();
	font = new sf::Font();
	if (!font->loadFromFile(_path))
	{
		LOG_ERROR_FORMAT("[Label] => font at path : {}  failed to load !", _path)
		Free();
	}
	text->setFont(*font);
}

Engine::UI::Label::Label(const Label& _copy) : super(_copy) { }

Engine::UI::Label::~Label()
{
	Free();
}

void Engine::UI::Label::Free()
{
	delete text;
	text = nullptr;
	delete font;
	font = nullptr;
}

void Engine::UI::Label::SetCharacterSize(const int _size)
{
	checkLow((text != nullptr), "[Label] => label is nullptr")
	text->setCharacterSize(_size);
}

void Engine::UI::Label::SetColor(sf::Color _color)
{
	checkLow((text != nullptr), "[Label] => label is nullptr")
	text->setFillColor(_color);
}

void Engine::UI::Label::SetString(const char* _str)
{
	checkLow((text != nullptr), "[Label] => label is nullptr")
	text->setString(_str);
}

void Engine::UI::Label::SetPosition(sf::Vector2f _position)
{
	checkLow((text != nullptr), "[Label] => label is nullptr")
	text->setPosition(_position);
}

sf::Vector2f Engine::UI::Label::Position() const
{
	check((text != nullptr), "[Label] => label is nullptr", sf::Vector2f(0, 0))
	text->getPosition();
}

void Engine::UI::Label::SetScale(sf::Vector2f _scale)
{
	checkLow((text != nullptr), "[Label] => label is nullptr")
	text->setScale(_scale);
}

sf::Vector2f Engine::UI::Label::Scale() const
{
	check((text != nullptr), "[Label] => label is nullptr", sf::Vector2f(0, 0))
		text->getScale();
}

void Engine::UI::Label::SetOrigin(sf::Vector2f _origin)
{
	checkLow((text != nullptr), "[Label] => label is nullptr")
	text->setOrigin(_origin);
}

sf::Vector2f Engine::UI::Label::Origin() const
{
	check((text != nullptr), "[Label] => label is nullptr", sf::Vector2f(0, 0))
	text->getOrigin();
}

sf::FloatRect Engine::UI::Label::GlobalBounds() const
{
	check((text != nullptr), "[Label] => label is nullptr", sf::FloatRect(0, 0, 0, 0))
	text->getGlobalBounds();
}

void Engine::UI::Label::Draw()
{
	if (text == nullptr) return;
	Engine::Window::EngineWindow::Instance()->Draw(text);
}
