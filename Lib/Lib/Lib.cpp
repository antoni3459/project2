#include <iostream>
#include "FString.h"
#include "Object.h"
#include "Interger.h"
#include "Boolean.h"
#include "Process.h"
#include "Environment.h"
#include "CoreIO.h"
#include "Directory.h"
#include "TestWritter.h"
#include "TextReader.h"
#include "FileStream.h"
#include "Path.h"
#include "File.h"
#include "Console.h"
#include "EConsoleColor.h"
#include "Datetime.h"
#include "EDayOfWeek.h"
#include "BoxFile.h"
#include "ShObjIdl_core.h"
#include "windows.h"
#include "Window.h"
#include "WindowMenu.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "Shape.h"
#include "FieldInfo.h"
#include "MethodInfo.h"
#include "ParamatereInfo.h"
#include "Enum.h"
#include "Hash.h"
#include "Map.h"
#include "KeyValuePair.h"
#include "WebClient.h"
#include "Uri.h"

//using namespace Core::PrimitiveType;
//using namespace Core;
//
//template <typename Base, typename Derived>
//static bool Instanceof(Derived*)
//{
//	return std::is_same<Base, Derived>::value;
//}
//
//#define instanceof(a,b)Instanceof<a>(b)
using namespace Core::PrimitiveType;
using namespace Core;
using namespace Core::IO;
using namespace Core::Net;

//class A : public Object
//{
//
//public:
//	void Test(const FString& _msg, const FString& a)
//	{
//		LOG(_msg);
//		LOG(a);
//	}
//};
//
//ENUM(Test, Giusy = 1,Gabriel=15,Hugo)
//ENUM(Test1, Aymeric = 1,Thibaud=2,Benoit=5, Pierre)

class Progress :public Object
{
public:
	void Display(float _value)
	{
		const char* _str = "====================================================================";
		const int _width = 60;
		const int _pad = (_value / 100) * _width;
		const int _rpad = _width - _pad;
		printf("\r%.0f%% [%.*s%s%*s]", _value, _pad, _str, ">", _rpad, "");
	}
};


int main()
{
	/*Core::PrimitiveType::FString _str=Core::PrimitiveType::FString("hello");
	std::cout << _str;*/
	//MessageBox(nullptr, L"Comment ça va ?", L"Test", MB_OK | MB_ICONERROR);
	/*object o = new Object();
	DateTime* time = new DateTime(0, 0, 0, 0);
	if (instanceof(Object, o))
	{
		std::cout << "o is Object" << std::endl;
	}
	if (instanceof(Object, time))
	{
		std::cout << "time is object" << std::endl;
	}
	if (instanceof(DateTime, time))
	{
		std::cout << "time is DateTime" << std::endl;
	}
	return 0;*/



	//std::cout << *Test::Giusy << std::endl;
	//for (Test1 t : Test1Support::Values())
	//{
	//	std::cout << *t << std::endl;
	//}

	//pour le hashage

	//Integer a = 50;
	//Integer b = 50;

	//Integer hash = a.GetHashCode();
	//LOG(hash);
	//Integer hash2 = b.GetHashCode();
	//LOG(hash2);

	//Collections::Map<Integer, FString>map = Collections::Map<Integer, FString>{
	//
	//	{0,"hello"},
	//	{1000,"World"}
	//};
	//map.Remove(0);
	//LOG(map[1000]);
	//map.Add(55, "Hey");
	//LOG(map[55]);
	

	////URL
	//try
	//{
	//	WebClient _request = WebClient(Uri(".........................(url a telecharger"));
	//	_request.DownloadFile("......(nom du fichier quand il sera télécharger");
	//}
	//catch (const Exception& e)
	//{
	//	LOG_ERROR(e);
	//}
	Progress progressBar = Progress();
	WebClient client = WebClient(Uri(".........................(url a telecharger"));
	client.OnDownloadProgress.AddDynamic(&progressBar, &Progress::Display);
	client.DownloadFile("......(nom du fichier quand il sera télécharger");
	return 0;

}
