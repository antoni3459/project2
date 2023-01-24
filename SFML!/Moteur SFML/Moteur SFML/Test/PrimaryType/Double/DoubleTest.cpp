#include "DoubleTest.h"
#include "../../../Engine/PrimaryType/Double/Double.h"
#include "../../../Engine/PrimaryType/Boolean/Boolean.h"
#include "../../../Engine/Utils/DebugMacro.h"

void Test::DoubleTest::Test()
{
	Engine::PrimaryType::Double _a = 10.0;
	Engine::PrimaryType::Double _b = 15.0;

	checkLow((_a < _b), "a is not < to b")
		checkLow((_b > _a), "a is not > to b")

		Engine::PrimaryType::Double _c = Engine::PrimaryType::Double::Parse("15.0f");
	checkLow((_c == 15.0), "c is not equals to 15.0f")
		checkLow((_c != _a), "c is not != to _a")
		checkLow((_b >= _c), "b is not >= to c")
		checkLow((_a <= _c), "a is not <= to c")

		Engine::PrimaryType::Double _d = _a + _b;
	checkLow((_d == 25.0), "d is not equals to a + b = 25.0f")
		_d = _b - _a;
	checkLow((_d == 5.0), "d is not equals to a - b = 5.0f")
		_d = _b * _a;
	checkLow((_d == 150.0), "d is not equals to a * b = 150.0f")
		_d = _a / 2.0;
	checkLow((_d == 5.0), "d is not equals to a / 2 = 5.0f")
		_d += 250.0f;
	checkLow((_d == 255.0), "d is not equals to d += 250 = 255.0f")
		_d -= 30.0f;
	checkLow((_d == 225.0), "d is not equals to d -= 30 = 225.0f")
		_d *= 2;
	checkLow((_d == 450.0), "d is not equals to d *= 2 = 450.0f")
		_d /= 4.0f;
	checkLow((_d == 112.5), "d is not equals to _d /=4 = 112.5f")

		_d = Engine::PrimaryType::Double::NaN;
	checkLow((Engine::PrimaryType::Double::IsNaN(_d)), "d is not equals to Nan")
		_d = Engine::PrimaryType::Double::PositiveInfinity;
	checkLow((Engine::PrimaryType::Double::IsPositiveInfinity(_d)), "d is not equals to PositiveInfinity")
		_d = Engine::PrimaryType::Double::NegativeInfinity;
	checkLow((Engine::PrimaryType::Double::IsNegativeInfinity(_d)), "d is not equals to NegativeInfinity")

		Engine::Utils::Console::Log("[Float][Test] => sucessful !");
}
