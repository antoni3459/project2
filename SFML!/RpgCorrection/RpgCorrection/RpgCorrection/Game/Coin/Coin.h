﻿#pragma once
#include "../../Core/GameObject/GameObject.h"

namespace Core
{
    class Gif;
}
namespace Game
{
    class Coin : public Core::GameObject
    {
        DECLARE_CLASS_INFO(Coin, GameObject)
#pragma region f/p
    private:
        Core::Gif* gif = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        Coin();
        Coin(const Coin&) = delete;
        ~Coin() override;
#pragma endregion constructor/destructor
#pragma region methods
    public:
        void OnUpdate() override;
        void OnCollisionEnter(GameObject* _object) override;
#pragma endregion methods
    };
}
