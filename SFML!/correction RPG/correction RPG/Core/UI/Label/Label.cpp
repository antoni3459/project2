#include "Label.h"
#include "../../Utils/Debug/Debug.h"
#include "../../Manager/Font/FontManager.h"
#include <SFML/Graphics.hpp>

Core::UI::Label::Label(Window* _owner, const char* _text):super( _owner)
{
	text = new sf::Text();
	text->setString(_text);
	sf::Font* _font = Manager::FontManager::Instance()->Load("OldLondonAlternate");
	checkLow((_font != nullptr), "[Label] => font is nullptr !");
	text->setFont(*_font);

	drawable = text;
}

Core::UI::Label::Label(const Label& _copy) :super(_copy)
{
	text = _copy.text;
	drawable = text;

}

void Core::UI::Label::SetText(const char* _text) const
{
	checkLow(IsValid(), "[Label] => text is null");
	text->setString(*_text);
}

void Core::UI::Label::SetFont(const sf::Font* _font) const
{

	checkLow(IsValid(), "[Label] => text is null")
		text->setFont(*_font);

}

void Core::UI::Label::SetCharactereSize(int _size)
{
	checkLow(IsValid(), "[Label] => text is null")
		text->setCharacterSize(_size);
}

void Core::UI::Label::SetPosition(const sf::Vector2f& _position)
{
	checkLow(IsValid(), "[Label] => text is null")
		text->setPosition(_position);
}

sf::Vector2f Core::UI::Label::Position() const
{
	Check(IsValid(), "[Label] => text is null",sf::Vector2f(0, 0))
	 return text->getPosition();
}

void Core::UI::Label::SetOrigin(const sf::Vector2f& _origin)
{
	checkLow(IsValid(), "[Label] => text is null")
		text->setPosition(_origin);
}

sf::Vector2f Core::UI::Label::Origin() const
{
	Check(IsValid(), "[Label] => text is null",sf::Vector2f(0,0))

	return text->getOrigin();
}

void Core::UI::Label::SetScale(const sf::Vector2f& _scale)
{
	checkLow(IsValid(), "[Label] => text is null")
		text->setPosition(_scale);
}

sf::Vector2f Core::UI::Label::Scale() const
{
	Check(IsValid(), "[Image] => sprite is nullptr", sf::Vector2f(0, 0))

		return text->getScale();
}

sf::FloatRect Core::UI::Label::GlobalBounds() const
{
	Check(IsValid(), "[Image] => sprite is nullptr", sf::FloatRect(0, 0, 0, 0))

		return text->getGlobalBounds();
}
