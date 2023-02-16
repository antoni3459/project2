#pragma once
#include "../../Utils/Singleton/Singleton.h"
#include <SFML/Graphics/Texture.hpp>


namespace Engine::Manager
{
    class TextureManager :public Utils::Singleton<TextureManager>
    {
#pragma region f/p
    private:
        std::map<std::string, sf::Texture*> textures = std::map<std::string, sf::Texture*>();
#pragma endregion f/p
#pragma region constructor
    public:
        TextureManager() = default;
#pragma endregion constructor
#pragma region methods
    public:
        void Init();
        void LoadTexture(const char* _path);
        sf::Texture* GetTexture(const std::string& _fontName);
#pragma endregion methods
#pragma region override
    public:
        void OnDestroy() override;
    };
}

