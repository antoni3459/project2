#pragma once
#include "../../Core/GameObject/GameObject.h"


namespace Game
{
	class Ground :public Core::GameObject
	{
		DECLARE_CLASS_INFO(Ground, GameObject)

	private:
		sf::RectangleShape* rectShape = nullptr;

	public:
		Ground(const sf::Vector2f& _size, const sf::Color& _color);
		
	public:
		void Draw(Core::Window* _window)override;
		void SetPosition(const sf::Vector2f& _position)override;
		void SetOrigin(const sf::Vector2f& _origin)override;
		void SetScale(const sf::Vector2f& _scale)override;
		sf::Vector2f Position()const override;
		sf::FloatRect GlobalBounds()const override;
	};
}
