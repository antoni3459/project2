#include "Help.h"
#include "Cls.h"
#include "EccoLeDauphins.h"
#include "Time.h"
#include "Help.h"
#include "Help.h"
#include "Help.h"



inline Help::Help(const std::initializer_list<std::string> _className)
{
	for (const std::string& _str : _className)
		classNames.push_back(_str);
}

Help::Help(const Help& _copy)
{
	classNames = _copy.classNames;
}

void Help::PushBack()
{

}

std::string Help::Name()
{
	return "Help";
}

std::string Help::Description()
{
	return "Provides help^information for windows comands. ";
}

void Help::Open()
{

}

int Help::FindIndex(const std::string _cmd)
{

}
void Help::Display()
{

}