#pragma once
#include "../UIElement.h"
#include <SFML/Graphics/Text.hpp>

namespace Core
{
    namespace UI
    {
        class Label : public UIElement
        {
            DECLARE_CLASS_INFO(Label, UIElement)
#pragma region f/p
        protected:
            sf::Text* text = nullptr;
#pragma endregion f/p
#pragma region constructor
        public:
            Label() = delete;
            Label(Window* _owner, const char* _text);
            Label(const Label& _copy);
#pragma endregion constructor
#pragma region methods
        public:
            void SetText(const char* _text) const;
            void SetFont(const sf::Font* _font) const;
            void SetCharacterSize(int _size) const;
#pragma endregion methods
#pragma region override
        public:
            void SetPosition(const sf::Vector2f& _position) override;
            sf::Vector2f Position() const override;
            void SetOrigin(const sf::Vector2f& _origin) override;
            sf::Vector2f Origin() const override;
            void SetScale(const sf::Vector2f& _scale) override;
            sf::Vector2f Scale() const override;
            sf::FloatRect GlobalBounds() const override;
#pragma endregion override
        };
    }
}
