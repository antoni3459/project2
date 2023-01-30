#pragma once
#include "../Window.h"

namespace Engine::Window
{
    class EngineWindow :
        public Window< EngineWindow>
    {
    private:
        sf::Clock clock = sf::Clock();

    public :
        void OnUpdate() override;
        void OnDraw()  override;
        void OnClear() const  override;
        void OnReciveEvent(const sf::Event& _event) const override;
    };
}

