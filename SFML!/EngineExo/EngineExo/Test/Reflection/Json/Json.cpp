#include "JsonTest.h"
#include "../../A.h"
#include <filesystem>
#include <fstream>

void Test::JsonTest::Test()
{
	A a = A();
	std::string _path = std::filesystem::current_path().parent_path().string();
	_path += "\\EngineExo";
	std::ofstream _outFile = std::ofstream(_path + "\\a.asset");
	a.Serialize(_outFile);

	std::ifstream _isFile = std::ifstream(_path + "\\a.asset");
	a.DeSerialize(_isFile);
}
