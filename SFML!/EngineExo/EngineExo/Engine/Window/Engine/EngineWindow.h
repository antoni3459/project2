#pragma once
#include "../Window.h"

namespace Engine::Window
{
    class EngineWindow :public Window< EngineWindow>
    {
        DECLARE_CLASS_INFO(EngineWindow, Window< EngineWindow>)

#pragma region f/p
    private:
        sf::Clock clock = sf::Clock();
#pragma endregion f/p

#pragma region method
    public:
        EngineWindow();
#pragma endregion method

#pragma region override
    public:
        void Open();
        void OnUpdate() override;
        //void OnDraw()  override;
        void OnClear() const  override;
        void OnReciveEvent(const sf::Event& _event) const override;
#pragma endregion override
    };
}

