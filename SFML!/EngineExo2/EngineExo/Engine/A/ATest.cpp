#include "ATest.h"

Engine::ATest::ATest() :super()
{

}

Engine::ATest::ATest(std::string _text, bool _toogle, int _nbr) :super()
{
	text = _text;
	toggle = _toogle;
	nbr = _nbr;
}

Engine::ATest::ATest(const ATest& _copy) :super(_copy)
{
	text = _copy.text;
	toggle = _copy.toggle;
	nbr = _copy.nbr;
}

std::string Engine::ATest::GetText() const
{
	return text;
}

bool Engine::ATest::GetToggle() const
{
	return toggle;
}

float Engine::ATest::GetNbr() const
{
	return nbr;
}

void Engine::ATest::SetText(float _text)
{
	text = _text;
}

void Engine::ATest::SetToggle(float _toggle)
{
	toggle = _toggle;
}

void Engine::ATest::SetNbr(float _nbr)
{
	nbr = _nbr;
}
