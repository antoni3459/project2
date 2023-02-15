#include "TextField.h"
#include "../../Manager/FontManager.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include "../../PrimaryType/Vector/Vector2.h"
#include "../../PrimaryType/String/String.h"

Engine::UI::TextField::TextField() :super()
{
	shape = new sf::RectangleShape(sf::Vector2f(200, 40));
	text.setString("");
	text.setFont(*Manager::FontManager::Instance()->GetFont("Arial"));
	text.setCharacterSize(12);
	inputDefaultText = inputText = "";
}

Engine::UI::TextField::TextField(const char* _label, const char* _defaultText, const PrimaryType::Vector2& _size):self()
{
	inputText = _label;
	inputDefaultText = _defaultText;
	text.setString(inputText);
	text.setOrigin(shape->getOrigin());
	((sf::RectangleShape*)shape)->setSize(_size);
}

Engine::UI::TextField::TextField(const char* _defaultText, const PrimaryType::Vector2& _size)
	: self(_defaultText,_defaultText, _size)
{
}

Engine::UI::TextField::TextField(const TextField& _copy) :super(_copy)
{
	inputText = _copy.inputText;
	inputDefaultText = _copy.inputDefaultText;
	isSelected = _copy.isSelected;
	text = _copy.text;
}

void Engine::UI::TextField::SetText(const char* _text)
{
	inputText = _text;
	text.setString(inputText);
}

void Engine::UI::TextField::Draw(sf::RenderWindow* _window)
{
	super::Draw(_window);
	_window->draw(text);
}


void Engine::UI::TextField::SetPosition(const PrimaryType::Vector2& _position)
{
	super::SetPosition(_position);
	text.setPosition(_position);
}

void Engine::UI::TextField::OnPointerEnter()
{
	shape->setFillColor(sf::Color(67, 82, 72, 255));

}

void Engine::UI::TextField::OnPointerExit()
{
	shape->setFillColor(sf::Color::White);
	if (text.getString() == "")text.setString(inputDefaultText);
	isSelected = false;//TODO change
}

void Engine::UI::TextField::OnPointerUnClick()
{
	if (text.getString() == "")
	{
		inputText = inputDefaultText;
		text.setString(inputDefaultText);
	}
	isSelected = false;
}

void Engine::UI::TextField::OnPointerClick(const sf::Event& _event)
{
	isSelected = true;
	if (text.getString() == inputDefaultText)
		text.setString("");
}

void Engine::UI::TextField::OnTextEntered(sf::Uint32 _unicode)
{
	if (!isSelected)return;
	if (_unicode == RETURN_KEY && inputText.size() != 0)
	{
		inputText.erase(inputText.size() - 1);
	}
	else if (_unicode < 128)
	{
		inputText += _unicode;
	}
	text.setString(inputText);
}