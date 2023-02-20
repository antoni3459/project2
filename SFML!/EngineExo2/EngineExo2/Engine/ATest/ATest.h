#pragma once
#include "../Object/Object.h"
#include "../UI/Slider/Slider.h"

namespace Engine
{
    namespace Window
    {
        class EngineWindow;
    }

    class ATest :public Object
    {
        DECLARE_CLASS_INFO(ATest, Object)

    private:
        bool toggle = false;
        float sliderInt = 0.0f;
        std::string textField = "";
        bool isClick = false;
        Engine::Window::EngineWindow* engineWindow = nullptr;

    public:
        UI::Slider* slider = nullptr;

    public:
        ATest();

    public:
        void OpenTest();
        void Draw();
        void SetToggle();
        void SetSlider();
        void SetTextField();
    };
}

