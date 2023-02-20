#pragma once
#include "../Element/UIElement.h"

namespace Engine::UI
{
    class Label : public UIElement
    {
        DECLARE_CLASS_INFO(Label, UIElement)

    private:
        sf::Text text = sf::Text();
        float slider = 0;

    public:
        Label();
        Label(const char* _text, int _characterSize = 12, const char* _fontName = "Arial");

    public:
        void SetFont(const char* _fontName);
        void SetCharacterSize(int _value);
        void SetColor(const sf::Color& _color);
        int SetCurrentValue();


    public:
        void SetPosition(const PrimaryType::Vector2& _position) override;
        void SetRotation(float _angle) override;
        void SetScale(const PrimaryType::Vector2& _scale) override;
        void SetOrigin(const PrimaryType::Vector2& _origin) override;
        void SetLabel(const char* _label) override;
        sf::Shape* Shape() const;
        PrimaryType::Vector2 Position() const override;
        float Rotation() const;
        PrimaryType::Vector2 Scale() const override;
        PrimaryType::Vector2 Origin() const override;
        PrimaryType::String LabelText() const override;
        void Draw(sf::RenderWindow* _window) override;
    };
}

