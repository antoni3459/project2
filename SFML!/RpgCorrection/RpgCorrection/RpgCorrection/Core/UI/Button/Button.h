#pragma once
#include "../UIElement.h"
#include "../../Event/Delegate/Delegate.h"

namespace Core
{
    namespace UI
    {
        class Button : public UIElement
        {
            DECLARE_CLASS_INFO(Button, UIElement)
#pragma region f/p
        private:
            class Image* image = nullptr;
        public:
            Event::Delegate<void> OnClick = nullptr;
#pragma endregion f/p
#pragma region constructor
        public:
            Button() = delete;
            Button(Window* _owner, const char* _path);
            Button(const Button& _copy);
            ~Button() override;
#pragma endregion constructor
#pragma region override
        public:
            bool IsValid() const override;
            void SetActive(bool _status) override;
            void Draw() override;
            void OnUpdate() override;
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
