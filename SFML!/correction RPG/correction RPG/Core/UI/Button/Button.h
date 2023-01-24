#pragma once
#include "../UIElement.h"
#include "../../Event/Delegate/Delegate.h"

namespace Core
{
	namespace UI
	{
		class Button :public UIElement
		{
			DECLARE_CLASS_INFO (Button, UIElement)

		private:
			class Image* image = nullptr;
		public:
			Event::Delegate<void> OnClick = nullptr;

		public:
			Button() = delete;
			Button(Window* _owner, const char* _path);
			Button(const Button& _copy);
			~Button()override;

		public:



			// Inherited via UIElement
			void SetActive(bool status)override;
			bool IsValid()const override;
			void Draw()override;
			void OnUpdate()override;
			
			virtual void SetPosition(const sf::Vector2f& _position) override;

			virtual sf::Vector2f Position() const override;

			virtual void SetOrigin(const sf::Vector2f& _origin) override;

			virtual sf::Vector2f Origin() const override;

			virtual void SetScale(const sf::Vector2f& _scale) override;

			virtual sf::Vector2f Scale() const override;

			virtual sf::FloatRect GlobalBounds() const override;

		};
	}
}
