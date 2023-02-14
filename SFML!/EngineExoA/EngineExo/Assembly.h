#pragma once
#include "Engine/Utils/ObjectMacro.h"

using namespace Engine;

#include "Engine\Component\Component.h"
REGISTER_TYPE(Component)
#include "Engine\Exception\Exception.h"
REGISTER_TYPE(Exception)
#include "Engine\GameObject\GameObject.h"
REGISTER_TYPE(GameObject)
#include "Engine\Object\Object.h"
REGISTER_TYPE(Object)
using namespace Engine::PrimaryType;

#include "Engine\PrimaryType\Boolean\Boolean.h"
REGISTER_TYPE(Boolean)
#include "Engine\PrimaryType\Double\Double.h"
REGISTER_TYPE(Double)
#include "Engine\PrimaryType\Float\Float.h"
REGISTER_TYPE(Float)
#include "Engine\PrimaryType\FString\String.h"
REGISTER_TYPE(String)
#include "Engine\PrimaryType\Integer\Integer.h"
REGISTER_TYPE(Integer)
#include "Engine\PrimaryType\ValueType\ValueType.h"
REGISTER_TYPE(ValueType)
#include "Engine\PrimaryType\Vector2\Vector2.h"
REGISTER_TYPE(Vector2)
using namespace Engine::Reflection;

#include "Engine\Reflection\Field\FieldInfo.h"
REGISTER_TYPE(FieldInfo)
#include "Engine\Selection\Selection.h"
REGISTER_TYPE(Selection)
#include "Engine\Transform\Transform.h"
REGISTER_TYPE(Transform)
using namespace Engine::UI;

#include "Engine\UIElement\UIElement.h"
REGISTER_TYPE(UIElement)
using namespace Test;

#include "Test\Component\PlayerComponent.h"
REGISTER_TYPE(PlayerComponent)
#include "Test\List\ListTest.h"
REGISTER_TYPE(ListTest)
#include "Test\PrimaryType\Double\DoubleTest.h"
REGISTER_TYPE(DoubleTest)
#include "Test\PrimaryType\Float\FloatTest.h"
REGISTER_TYPE(FloatTest)
#include "Test\PrimaryType\Integer\IntegerTest.h"
REGISTER_TYPE(IntegerTest)
#include "Test\Reflection\ReflectionTest.h"
REGISTER_TYPE(ReflectionTest)
#include "Test\Reflection\Json\JsonTest.h"
REGISTER_TYPE(JsonTest)

