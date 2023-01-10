#pragma once
#include "../FB_UIElement.h"

class FB_Image : public FB_UIElement
{
private:
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;

public :
	FB_Image(Window* _owner, const char* _path);
	FB_Image(FB_Image& _copy);
	virtual ~FB_Image()override;

private:
	void Free();
public:
	sf::FloatRect GetGlobalBounds()const;

public:
	void SetPosition(const sf::Vector2f& _position) override;
	void SetScale(const sf::Vector2f& _scale) override;
	void Draw(Window* _window) override;
	void SetOrigin(const sf::Vector2f& _origin) override;

	// Inherited via FB_UIElement
	virtual sf::FloatRect GetGlobalBound() const override;
};

