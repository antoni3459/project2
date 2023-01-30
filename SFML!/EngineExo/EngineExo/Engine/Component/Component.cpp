#include "Component.h"
#include "../Utils/DebugMacro.h"

Engine::Object& Engine::Component::operator=(const Object* _obj)
{
	const Component* _other = dynamic_cast<const Component*>(_obj);
	check((_other != nullptr), "[Componement] operator= _obj is not Componement",*this)
		super::operator=(_obj);
	enabled = _other->enabled;
	gameobject = _other->gameobject;
	return *this;
}
