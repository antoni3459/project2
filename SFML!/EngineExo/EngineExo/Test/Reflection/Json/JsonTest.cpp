#include "JsonTest.h"
#include "../../A.h"
#include "../../C.h"

#include <filesystem>
#include <fstream>

void Test::JsonTest::Test()
{
    std::string _path = std::filesystem::current_path().parent_path().string();
    _path += "\\EngineExo";

//    A a = A();
//    std::ofstream _outFile = std::ofstream( _path + "\\a.asset");
//    a.Serialize(_outFile);
//    _outFile.close();

    A b = A();
    std::ifstream _inFile = std::ifstream(_path + "\\a.asset");
    b.DeSerialize(_inFile);
    _inFile.close();


}
