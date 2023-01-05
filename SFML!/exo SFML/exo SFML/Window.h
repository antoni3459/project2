#pragma once
#include <SFML/Graphics.hpp>

class Window
{
private:
	float width = 900;
	float height = 800;
	const char* title = "default Window";
	sf::RenderWindow* window = nullptr;
protected :
	bool eventIfNotFocus = false;


public:
	Window() = default;
	Window(const float _width, const float _height, const char* _title);
	Window(const Window& _copy) = delete;
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
	virtual void OnDraw()=0;
	virtual void OnUpdate()=0;
	virtual void OnReceiveEvent(sf::Event& _event);

};

