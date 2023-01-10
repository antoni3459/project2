#include "FB_TextureManager.h"
#include <format>

sf::Texture* FB_TextureManager::Get(const char* _path)
{
    if (!texture.contains(_path))
    {
        sf::Texture* _texture = new sf::Texture();
        if (!_texture->loadFromFile(_path))
            throw std::exception(std::format("[Texture Manager] =>can't load texture at path: {}", _path).c_str());
        texture.insert(std::pair(_path, _texture));
        return _texture;
    }
    return texture[_path];
}

void FB_TextureManager::Ondestroy()
{
    for (std::pair<const char*, sf::Texture*> _pair : texture)
    {
        delete _pair.second;
    }
    texture.clear();
}
