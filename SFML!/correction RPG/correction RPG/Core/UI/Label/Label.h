#pragma once
#include "../UIElement.h"

namespace Core
{
	namespace UI
	{
		class Label : public UIElement
		{
			DECLARE_CLASS_INFO (Label, UIElement)

		protected:
			sf::Text* text = nullptr;

		public:
			Label() = delete;
			Label(Window* _owner, const char* _text);
			Label(const Label& _copy);

		public:
			void SetText(const char* _text)const;
			void SetFont(const sf::Font* font)const;
			void SetCharactereSize(int _size);

		public:
			void SetPosition(const sf::Vector2f& _position) override;
			sf::Vector2f Position() const override;
			void SetOrigin(const sf::Vector2f& _origin) override;
			sf::Vector2f Origin() const override;
			void SetScale(const sf::Vector2f& _scale) override;
			sf::Vector2f Scale() const override;
			sf::FloatRect GlobalBounds() const override;
		};
	}
}

