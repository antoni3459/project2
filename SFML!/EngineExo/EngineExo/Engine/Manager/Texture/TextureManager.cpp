#include "TextureManager.h"
#include <filesystem>
#include <ranges>

#include "../../Utils/DebugMacro.h"

namespace fs = std::filesystem;

void Engine::Manager::TextureManager::Init()
{
    LoadTexture("../Texture");
}

void Engine::Manager::TextureManager::LoadTexture(const char* _path)
{
    for (const fs::directory_entry& _entry : fs::recursive_directory_iterator(_path))
    {
        if (!_entry.is_regular_file()) continue;
        const fs::path& _filePath = _entry.path();
        if (_filePath.extension() != ".jpg" && _filePath.extension() != ".png") continue;
        sf::Texture* texture = new sf::Texture();
        if (!texture->loadFromFile(_filePath.string()))
        {
            LOG_ERROR(_filePath.string() + " can't load font !")
                continue;
        }
        PrimaryType::String _name = _filePath.string().c_str();
        _name = _name.Replace('\\', '/');
        _name = _name.SubString(_name.FindLastOf('/') + 1);
        _name = _name.SubString(0, _name.FindFirstOf('.')).Trim();
        textures.insert(std::pair<std::string, sf::Texture*>(_name.ToCstr(), texture));
    }
}

sf::Texture* Engine::Manager::TextureManager::GetTexture(const std::string& _fontName)
{
    check((textures.contains(_fontName)), _fontName + " doesn't exist !", nullptr)
        return textures[_fontName];
}

void Engine::Manager::TextureManager::OnDestroy()
{
    for (sf::Texture*& _textures : textures | std::ranges::views::values)
    {
        delete _textures;
        _textures = nullptr;
    }
    textures.clear();
}
