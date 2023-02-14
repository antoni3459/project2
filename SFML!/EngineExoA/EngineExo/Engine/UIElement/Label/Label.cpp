#include "Label.h"

Engine::UI::Label::Label(const std::string _text,const int _height,const int _posX,const int _posY)
{
	font = new sf::Font();
	text = new sf::Text();

	if (!font->loadFromFile("../Font/Vogue.ttf")) return;
	text->setFont(*font);
	text->setString(_text);
	text->setCharacterSize(_height);
	text->setPosition(_posX, _posY);
}

Engine::UI::Label::Label(const Label& _copy)
{
	text = _copy.text;
	font = _copy.font;
}

Engine::UI::Label::~Label()
{
	delete text;
	text = nullptr;
	delete font;
	font=nullptr;
}

void Engine::UI::Label::OnUpdate()
{

}

void Engine::UI::Label::OnDraw()
{
	Draw(text);
}
