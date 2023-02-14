#pragma once
#include "Engine/Utils/ObjectMacro.h"

using namespace Engine;

#include "Engine\Component\Component.h"
REGISTER_TYPE(Component)
#include "Engine\GameObject\GameObject.h"
REGISTER_TYPE(GameObject)
#include "Engine\Object\Object.h"
REGISTER_TYPE(Object)
#include "Engine\Transform\Transform.h"
REGISTER_TYPE(Transform)
#include "EngineExo\Engine\Component\Component.h"
REGISTER_TYPE(Component)
#include "EngineExo\Engine\GameObject\GameObject.h"
REGISTER_TYPE(GameObject)
#include "EngineExo\Engine\Object\Object.h"
REGISTER_TYPE(Object)
#include "EngineExo\Engine\Transform\Transform.h"
REGISTER_TYPE(Transform)
using namespace Engine::PrimaryType;

#include "Engine\PrimaryType\Boolean\Boolean.h"
REGISTER_TYPE(Boolean)
#include "Engine\PrimaryType\Integer\Integer.h"
REGISTER_TYPE(Integer)
#include "Engine\PrimaryType\String\String.h"
REGISTER_TYPE(String)
#include "Engine\PrimaryType\Vector\Vector2.h"
REGISTER_TYPE(Vector2)
#include "EngineExo\Engine\PrimaryType\Boolean\Boolean.h"
REGISTER_TYPE(Boolean)
#include "EngineExo\Engine\PrimaryType\Integer\Integer.h"
REGISTER_TYPE(Integer)
#include "EngineExo\Engine\PrimaryType\String\String.h"
REGISTER_TYPE(String)
#include "EngineExo\Engine\PrimaryType\Vector\Vector2.h"
REGISTER_TYPE(Vector2)
using namespace Engine::Reflection;

#include "Engine\Reflection\Field\FieldInfo.h"
REGISTER_TYPE(FieldInfo)
#include "EngineExo\Engine\Reflection\Field\FieldInfo.h"
REGISTER_TYPE(FieldInfo)
using namespace Test;

#include "EngineExo\Test\Component\PlayerComponent.h"
REGISTER_TYPE(PlayerComponent)
#include "EngineExo\Test\PrimaryType\Integer\IntegerTest.h"
REGISTER_TYPE(IntegerTest)
#include "Test\Component\PlayerComponent.h"
REGISTER_TYPE(PlayerComponent)
#include "Test\PrimaryType\Integer\IntegerTest.h"
REGISTER_TYPE(IntegerTest)

