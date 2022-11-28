#include "Register.h"
#include <windowsx.h>
#include <exception>

std::map<std::string, Core::Object*> Core::Register::RegisterValue(std::string _name)
{
	std::map< std::string,Core::Object* >_regiValue = std::map< std::string, Core::Object* >();
	if (_regiValue[_name] == regiValue[_name])
		throw std::exception("complet");
	regiValue[_name] = _regiValue[_name];

	return regiValue;
}



std::map<std::string, bool> Core::Register::RegisterType(std::string _name)
{
	
	return std::map<std::string, bool>();
}
