#pragma once
#include "../Interactable.h"
#include "../../Label/Label.h"

namespace Engine::UI
{
	UCLASS()
	class Slider : public Interactable
	{
		DECLARE_CLASS_INFO(Slider, Interactable)

#pragma region f/p
	private:
		sf::RectangleShape* line = nullptr;
		sf::CircleShape* circle = nullptr;
		Label* percentage = nullptr;
		float percentageFloat = 0.0f;
#pragma endregion 
#pragma region constructor
	public:
		Slider() = default;
		Slider(Window::EngineWindow* _owner);
		~Slider() override;
#pragma endregion 
#pragma region methods
	private:
		void Free();
	public:
		void Move();
#pragma endregion
#pragma region override
	public:
		void SetPosition(sf::Vector2f _position) override;
		sf::Vector2f Position() const override;
		void SetScale(sf::Vector2f _scale) override;
		sf::Vector2f Scale() const override;
		void SetOrigin(sf::Vector2f _origin) override;
		sf::Vector2f Origin() const override;
		sf::FloatRect GlobalBounds() const override;
		void Draw() override;
		void OnUpdate() override;
#pragma endregion 
	};
}

