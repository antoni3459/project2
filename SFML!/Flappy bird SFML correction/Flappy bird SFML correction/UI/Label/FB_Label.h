#pragma once
#include "../FB_UIElement.h"
class FB_Label : public FB_UIElement
{
private:
	sf::Text* text = nullptr;
	sf::Font* font = nullptr;

public:
	FB_Label(Window* _owner, const char* _text);
	~FB_Label()override;

private:
	void Free();
public:
	void SetCaractereSize(const int _size) ;
	void SetColor(const sf::Color& _color);
	void SetText(const char* _text);
public:	

	virtual void SetPosition(const sf::Vector2f& _position) override;
	virtual void SetScale(const sf::Vector2f& _scale) override;
	virtual void Draw(Window* _window) override;
	virtual void SetOrigin(const sf::Vector2f& _origin) override;


	// Inherited via FB_UIElement
	virtual sf::FloatRect GetGlobalBound() const override;

};

