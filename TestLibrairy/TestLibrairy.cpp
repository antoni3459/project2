#include <iostream>
#include <FString.h>
#include <Object.h>

int main()
{
	//Core::Object* o = new Core::Object();
	//Core::PrimitiveType::FString str = Core::PrimitiveType::FString("salut");
	//std::cout << str;
	//delete o;

	Core::PrimitiveType::FString _str = "Hello World";
	_str = _str.Replace("", "");
}
