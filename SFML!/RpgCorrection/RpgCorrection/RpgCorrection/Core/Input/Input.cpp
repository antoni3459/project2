#include "Input.h"
#include <SFML/Window/Keyboard.hpp>

void Core::Input::Init()
{
    for (EKey key : EKeySupport::Values())
        keys.insert(std::pair(key, EKeyType::None));
}
void Core::Input::Update()
{
    // if (currentEvent == nullptr) return;
    for (EKey _key : EKeySupport::Values())
    {
        if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)_key))
        {
            if (keys[_key] == EKeyType::None)
                keys[_key] = EKeyType::Down;
            else if (keys[_key] == EKeyType::Down)
                keys[_key] = EKeyType::Pressed;
        }
        else
        {
            if (keys[_key] == EKeyType::Up)
                keys[_key] = EKeyType::None;
            else if (keys[_key] == EKeyType::Down || keys[_key] == EKeyType::Pressed)
                keys[_key] = EKeyType::Up;
        }
    }
}

bool Core::Input::IsKeyDown(const EKey& _key)
{
    return keys[_key] == EKeyType::Down;
}
bool Core::Input::IsKey(const EKey& _key)
{
    return keys[_key] == EKeyType::Pressed;
}
bool Core::Input::IsKeyUp(const EKey& _key)
{
    return keys[_key] == EKeyType::Up;
}
