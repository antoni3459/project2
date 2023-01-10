#pragma once
#include "../../Window/Window.h"
#include "../../UI/Image/FB_Image.h"
#include "../Bird/FB_Bird.h"

#define TIME_FOR_SPAWN 1.5f
#define GAP 150

class FB_Game : public Window
{
#pragma region f/p
private:
	bool isStarted = false;
	FB_Image* background = nullptr;
	FB_Bird* bird = nullptr;
	class FB_Score* score = nullptr;
	sf::Clock spawnerClock = sf::Clock();
#pragma endregion f/p
#pragma region constructor

public:
	FB_Game();
	~FB_Game()override;
#pragma endregion constructor

private:
	void Start();
	void SpawnPipe();
	void OnBirdDie();
public:
	void InitBackround();

	void InitMenus() override;
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
	virtual void OnRecieveEvent(sf::Event& _event)override;
public:

};

