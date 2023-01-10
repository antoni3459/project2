#pragma once
#include "../FB_UIElement.h"
#include "../../Event/Delegate/Delegate.h"

class FB_Image;

class FB_Button : public FB_UIElement
{
private:
    FB_Image* image = nullptr;
public:
    Delegate<void> OnClick = nullptr;
public:
    FB_Button(Window* _owner, const char* _path);
    FB_Button(const FB_Button& _copy);
    virtual ~FB_Button()override;

public:
    void OnUpdate();

public:
    virtual void SetPosition(const sf::Vector2f& _position) override;
    virtual void SetScale(const sf::Vector2f& _scale) override;
    virtual void Draw(Window* _window) override;
    virtual void SetOrigin(const sf::Vector2f& _origin) override;


    // Inherited via FB_UIElement
    virtual sf::FloatRect GetGlobalBound() const override;

};

