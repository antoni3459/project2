#include "Button.h"
#include "../Image/Image.h"
#include "../../Window/Window.h"

Core::UI::Button::Button(Window* _owner, const char* _path) :super(_owner)
{
    image = new Image(_owner, _path);
    checkLow(image->IsValid(),"image is not valid !")
}

Core::UI::Button::Button(const Button& _copy) :super(_copy)
{
    image = _copy.image;
}

Core::UI::Button::~Button()
{
    delete image;
    image = nullptr;
}

bool Core::UI::Button::IsValid() const
{
    return image==nullptr && image->IsValid();
}

void Core::UI::Button::Draw()
{
    image->Draw();
}

void Core::UI::Button::OnUpdate()
{
    const sf::Vector2i _mousePosition = sf::Mouse::getPosition(*owner->Render());
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && image->GlobalBounds().contains(sf::Vector2f(_mousePosition.x, _mousePosition.y)))
    {
        checkLow(OnClick.IsValid(), "[Button] => Delegate 'OnClick' is not valid !")
            OnClick.Invoke();
    }
}

void Core::UI::Button::SetPosition(const sf::Vector2f& _position)
{
    image->SetPosition(_position);
}

sf::Vector2f Core::UI::Button::Position() const
{
    return image->Position();
}

void Core::UI::Button::SetOrigin(const sf::Vector2f& _origin)
{
    image->SetPosition(_origin);

}

sf::Vector2f Core::UI::Button::Origin() const
{
    return image->Origin();
}

void Core::UI::Button::SetScale(const sf::Vector2f& _scale)
{
    image->SetPosition(_scale);

}

sf::Vector2f Core::UI::Button::Scale() const
{
    return image->Scale();
}

sf::FloatRect Core::UI::Button::GlobalBounds() const
{
    return image->GlobalBounds();
}
