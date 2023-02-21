#pragma once
#include "../Object/Object.h"
#include "../UI/Slider/Slider.h"

namespace Engine
{
    class ATest :public Object
    {
        DECLARE_CLASS_INFO(ATest, Object)

    private:
        bool toggle = false;
        float sliderInt = 0.0f;
        std::string textField = "";
        bool isClick = false;
        //UI::Slider* slider = nullptr;

    public:
        ATest() = default;

    public:
        void OpenTest();
        void Draw();
        void SetToggle();
        void SetSlider();
        void SetTextField();
    };
}

