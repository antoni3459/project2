#pragma once
#include "../Object/Object.h"
#include "SFML/Graphics.hpp"


namespace Engine::Window
{
	class EngineWindow;
}
namespace Engine::UI
{
	UCLASS()
	class UI_Elements : public Object
	{
		DECLARE_CLASS_INFO(UI_Elements, Object)

#pragma region f/p
	protected:
		Window::EngineWindow* owner = nullptr;
		bool isActive = false;
#pragma endregion 
#pragma region constructor
	public:
		UI_Elements() = default;
		UI_Elements(Window::EngineWindow* _owner);
		~UI_Elements() override;
#pragma endregion 
#pragma region methods
	public:
		virtual void SetPosition(sf::Vector2f _position);
		virtual sf::Vector2f Position() const;
		virtual void SetScale(sf::Vector2f _scale);
		virtual sf::Vector2f Scale() const;
		virtual void SetOrigin(sf::Vector2f _origin);
		virtual sf::Vector2f Origin() const;
		virtual sf::FloatRect GlobalBounds() const;
		virtual void Draw();
		virtual void OnUpdate();
		void SetActive(bool _statue);
		bool IsActive() const;
#pragma endregion 
	};
}

