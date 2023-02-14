#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

namespace Engine::PrimaryType
{

namespace Engine::UI
{
	UCLASS()
	class UIElement : public Object
	{
		DECLARE_CLASS_INFO(UIElement, Object)

	protected:
		sf::Shape* shape = nullptr;
		sf::Text labelText = sf::Text();
		bool canInteract = true;
		bool isActive = true;

	public:
		UIElement() = default;
		UIElement(const char* _label);
		virtual ~UIElement() override;

	public:
		virtual void SetPosition(const PrimaryType::Vector2& _position);
		virtual void SetRotation(const PrimaryType::Vector2& _rotation);
		virtual void SetScale(const PrimaryType::Vector2& _scale);
		virtual void SetOrigin(const PrimaryType::Vector2& _position);
		virtual void SetIsActive(bool _status);
		virtual void SetCanInteract(bool _status);
		virtual void SetLabel(const char* _label);
		virtual bool CanInteract()const;
		virtual bool IsActive()const;
		virtual PrimaryType::Vector2 Position()const;
		virtual PrimaryType::Vector2 Rotation()const;
		virtual PrimaryType::Vector2 Scale()const;
		virtual PrimaryType::Vector2 Origin()const;
		virtual PrimaryType::String Label()const;
		virtual void Draw(sf::RenderWindow* _window);

	public:
		Object& operator=(const Object* _obj)override;
	};
}

