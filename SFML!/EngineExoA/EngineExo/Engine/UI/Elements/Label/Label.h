#pragma once
#include "../UI_Elements.h"

namespace Engine::UI
{
	UCLASS()
	class Label : public UI_Elements
	{
		DECLARE_CLASS_INFO(Label, UI_Elements)

#pragma region f/p
	private:
		sf::Text* text = nullptr;
		sf::Font* font = nullptr;
#pragma endregion 
#pragma region constructor
	public:
		Label() = default;
		Label(Window::EngineWindow* _owner, const char* _path);
		~Label() override;
#pragma endregion
#pragma region methods
	private:
		void Free();
	public:
		void SetCharacterSize(const int _size);
		void SetColor(sf::Color _color);
		void SetString(const char* _str);
#pragma endregion
#pragma region override
	public:
		void SetPosition(sf::Vector2f _position) override;
		sf::Vector2f Position() const override;
		void SetScale(sf::Vector2f _scale) override;
		sf::Vector2f Scale() const override;
		void SetOrigin(sf::Vector2f _origin) override;
		sf::Vector2f Origin() const override;
		sf::FloatRect GlobalBounds() const override;
		void Draw() override;
#pragma endregion 

	};
}


