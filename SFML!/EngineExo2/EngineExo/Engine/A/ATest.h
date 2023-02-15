#pragma once
#include "../Object/Object.h"

namespace Engine
{
	class ATest :public Object
	{
		DECLARE_CLASS_INFO(ATest, Object)

	private:
		std::string text = "";
		bool toogle = false;
		int nbr = 0;

	public:
		ATest(std::string _text, bool _toogle, int _nbr);

	public:

	};
}

