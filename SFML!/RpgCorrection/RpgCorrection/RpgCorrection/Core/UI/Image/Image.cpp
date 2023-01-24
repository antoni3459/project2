﻿#include "Image.h"

#include <SFML/Graphics/Texture.hpp>

#include "../../Manager/Texture/TextureManager.h"
#include "../../Utils/Debug/Debug.h"

Core::UI::Image::Image(Window* _owner, const char* _path) : super(_owner)
{
    sprite = new sf::Sprite();
    sf::Texture* _texture = Manager::TextureManager::Instance()->Load(_path);
    checkLow((_texture != nullptr), std::format("[Image] => texture: '{}' is nullptr !", _path))
    sprite->setTexture(*_texture);
    drawable = sprite;
}
Core::UI::Image::Image(const Image& _copy) : super(_copy)
{
    sprite = _copy.sprite;
    drawable = sprite;
}

void Core::UI::Image::SetPosition(const sf::Vector2f& _position)
{
    checkLow(IsValid(), "[Image] => sprite is nullptr")
    sprite->setPosition(_position);
}
sf::Vector2f Core::UI::Image::Position() const
{
    check(IsValid(), "[Image] => sprite is nullptr", sf::Vector2f(0,0))
    return sprite->getPosition();
}
void Core::UI::Image::SetOrigin(const sf::Vector2f& _origin)
{
    checkLow(IsValid(), "[Image] => sprite is nullptr")
    sprite->setOrigin(_origin);
}
sf::Vector2f Core::UI::Image::Origin() const
{
    check(IsValid(), "[Image] => sprite is nullptr", sf::Vector2f(0,0))
    return sprite->getOrigin();
}
void Core::UI::Image::SetScale(const sf::Vector2f& _scale)
{
    checkLow(IsValid(), "[Image] => sprite is nullptr")
    sprite->setScale(_scale);
}
sf::Vector2f Core::UI::Image::Scale() const
{
    check(IsValid(), "[Image] => sprite is nullptr", sf::Vector2f(0,0))
    return sprite->getScale();
}
sf::FloatRect Core::UI::Image::GlobalBounds() const
{
    check(IsValid(), "[Image] => sprite is nullptr", sf::FloatRect(0,0,0,0))
    return sprite->getGlobalBounds();
}
