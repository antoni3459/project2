#include "ATest.h"

Engine::ATest::ATest(std::string _text, bool _toogle, int _nbr) :super()
{
	text = _text;
	toogle = _toogle;
	nbr = _nbr;
}

Engine::ATest::ATest(const ATest& _copy) :super(_copy)
{
	text = _copy.text;
	toogle = _copy.toogle;
	nbr = _copy.nbr;
}

