#pragma once
#include "../Element/UIElement.h"
#include "../Interface/IPointerClickHandler.h"
#include "../Interface/IPointerEnterHandler.h"
#include "../Interface/IPointerExitHandler.h"
#include "../Interface/ITextEntered.h"

#define RETURN_KEY 8

namespace Engine::UI
{
    class TextField :public UIElement, public IPointerClickHandler, public ITextEntered, public IPointerEnterHandler, public IPointerExitHandler
    {
        DECLARE_CLASS_INFO(TextField, UIElement)

    private:
        std::string inputText = std::string();
        std::string inputDefaultText = std::string();
        bool isSelected = false;
        sf::Text text = sf::Text();

    public:
        TextField();
        TextField(const char* _label, const char* _defaultText, const PrimaryType::Vector2& _size);
        TextField(const char* _defaultText, const PrimaryType::Vector2& _size);

    public:
        void SetText(const char* _text);
        std::string GetInputText();

    public:
        void Draw(sf::RenderWindow* _window)override;
        void SetPosition(const PrimaryType::Vector2& _position);

        void OnTextEntered(sf::Uint32 _unicode)override;
        void OnPointerClick(const sf::Event& _event) override;
        void OnPointerEnter()override;
        void OnPointerExit()override;
        void OnPointerUnClick() override;


    };
}

