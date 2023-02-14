#pragma once
#include "../Interactable.h"

#define CAN_PUSH 0.25f

namespace Engine::UI
{
	UCLASS()
	class Toggle : public Interactable
	{
		DECLARE_CLASS_INFO(Toggle, Interactable)

#pragma region f/p
	private:
		bool isPressed = false;
		sf::RectangleShape* toggle = nullptr;
		sf::Clock timeBeforeTouchButton = sf::Clock();
#pragma endregion
#pragma region constructor
	public:
		Toggle() = default;
		Toggle(Window::EngineWindow* _owner);
		~Toggle() override;
#pragma endregion
#pragma region methods
	private:
		void Free();
	public:
		void Check();
#pragma endregion
#pragma region override
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

