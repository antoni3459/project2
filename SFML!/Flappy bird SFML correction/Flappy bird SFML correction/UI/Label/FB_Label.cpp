#include "FB_Label.h"

FB_Label::FB_Label(Window* _owner, const char* _text):FB_UIElement(_owner)
{
	text = new sf::Text();
	text->setString(_text);
	font = new sf::Font();
	if (!font->loadFromFile("C:/Users/PRAIT2401/Desktop/project2/project2/SFML!/Flappy bird SFML correction/font/Purple Smile.ttf"))
	{
		Free();
		return;
	}
	text->setFont(*font);
}

FB_Label::~FB_Label()
{
	Free();
}

void FB_Label::Free()
{
	delete text;
	text = nullptr;
		delete font;
	font=nullptr;
}

void FB_Label::SetCaractereSize(const int _size)
{
	text->setCharacterSize(_size);
}

void FB_Label::SetColor(const sf::Color& _color)
{
	text->setFillColor(_color);
}

void FB_Label::SetText(const char* _text)
{
	text->setString(_text);
}

void FB_Label::SetPosition(const sf::Vector2f& _position)
{
	text->setPosition(_position);
}

void FB_Label::SetScale(const sf::Vector2f& _scale)
{
	text->setScale(_scale);
}

void FB_Label::Draw(Window* _window)
{
	if (text != nullptr)
		_window->Draw(text);
}

void FB_Label::SetOrigin(const sf::Vector2f& _origin)
{
	text->setOrigin(_origin);
}

sf::FloatRect FB_Label::GetGlobalBound() const
{
	return text->getGlobalBounds();
}
