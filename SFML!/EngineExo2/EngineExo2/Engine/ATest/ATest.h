#pragma once
#include "../Object/Object.h"

namespace Engine
{
    class ATest :public Object
    {
        DECLARE_CLASS_INFO(ATest, Object)

    private:
        bool toggle = false;
        float slider = 0.0f;
        std::string textField = "";
        bool isClick = false;

    public:
        ATest();

    public:
        void Open();
        void Draw();
        void SetToggle();
        void SetSlider();
        void SetTextField();

    };
}

