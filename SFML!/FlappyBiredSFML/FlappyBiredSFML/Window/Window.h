#pragma once
#include <SFML/Graphics.hpp>
	
class Window
{
private:
	float width = 1920;
	float height = 1080;
	const char* title = "Flappy Bird";
protected:
	bool eventIfNotFocus = false;
	sf::RenderWindow* window = nullptr;

public:
	Window() = default;
	Window(const float _widht, const float _height, const char* _title);
	Window(const Window& ) = delete;
	virtual ~Window();

private:
	void Update();
public:
	void Open();
	void Close();
	bool IsOpen()const;
	bool HasFocus()const;
	void SetFrameLimit(const int _frame);
	void Draw(sf::Drawable* _drawable);

protected:
	virtual void OnDraw() = 0;	
	virtual void OnUpdate() = 0;
	virtual void OnReceiveEvent(sf::Event& _event);
};
