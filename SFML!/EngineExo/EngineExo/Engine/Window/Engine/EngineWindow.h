#pragma once
#include "../Window.h"

namespace Engine::Window
{
    class EngineWindow :public Window< EngineWindow>
    {
        DECLARE_CLASS_INFO(EngineWindow, Window< EngineWindow>)

    private:
        sf::Clock clock = sf::Clock();

    public:
        EngineWindow();
    public :
        void Open();
        void OnUpdate() override;
        //void OnDraw()  override;
        void OnClear() const  override;
        void OnReciveEvent(const sf::Event& _event) const override;
    };
}

