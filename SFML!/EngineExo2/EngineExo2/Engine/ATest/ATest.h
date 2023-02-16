#pragma once
#include "../Object/Object.h"

namespace Engine::UI
{
	class Button;
	class Label;
	class Slider;
	class TextField;
	class Toggle;
}

namespace Engine
{
	class ATest :public Object
	{
		DECLARE_CLASS_INFO(ATest, Object)

	private:
		std::string text = "";
		bool toggle = false;
		float nbr = 0;

	public:
		ATest();
		ATest(std::string _text, bool _toogle, int _nbr);

	public:
		std::string GetText()const;
		bool GetToggle()const;
		float GetNbr()const;

		void SetText(float _nbr);
		void SetToggle(float _nbr);
		void SetNbr(float _nbr);
	};
}

