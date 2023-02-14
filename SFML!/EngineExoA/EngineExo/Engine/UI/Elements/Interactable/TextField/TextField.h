#pragma once
#include "../Interactable.h"
#include "../../Label/Label.h"
#include "../../../PrimaryType/FString/FString.h"

#define CAN_CLICK 0.25f
#define CAN_TYPE 0.15f

namespace Engine::UI
{
	UCLASS()
	class TextField : public Interactable
	{
		DECLARE_CLASS_INFO(TextField, Interactable)
#pragma region f/p
	private:
		Label* text = nullptr;
		sf::RectangleShape* rect = nullptr;
		sf::Clock timeBeforeClick = sf::Clock();
		sf::Clock timeBeforeType = sf::Clock();
		PrimaryType::FString textStr = "test";
		bool onWriteMode = false;
#pragma endregion
#pragma region constructor
	public:
		TextField() = default;
		TextField(Window::EngineWindow* _owner, const char* _path);
#pragma endregion
#pragma region methods
	private:
		void Free();
		void Delete();
		void Write(sf::Event::TextEvent _c);
	public:
		void SetOnWriteMode();
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
