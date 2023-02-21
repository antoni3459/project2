#pragma once
#include "Engine/Utils/ObjectMacro.h"

using namespace Engine;

#include "Engine\ATest\ATest.h"
REGISTER_TYPE(ATest)
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
#include "Engine\PrimaryType\Integer\Integer.h"
REGISTER_TYPE(Integer)
#include "Engine\PrimaryType\String\String.h"
REGISTER_TYPE(String)
#include "Engine\PrimaryType\ValueType\ValueType.h"
REGISTER_TYPE(ValueType)
#include "Engine\PrimaryType\Vector\Vector2.h"
REGISTER_TYPE(Vector2)
using namespace Engine::Reflection;

#include "Engine\Reflection\Field\FieldInfo.h"
REGISTER_TYPE(FieldInfo)
#include "Engine\Transform\Transform.h"
REGISTER_TYPE(Transform)
using namespace Engine::UI;

#include "Engine\UI\Button\Button.h"
REGISTER_TYPE(Button)
#include "Engine\UI\Element\UIElement.h"
REGISTER_TYPE(UIElement)
#include "Engine\UI\Label\Label.h"
REGISTER_TYPE(Label)
#include "Engine\UI\Rectangle\RectangleBox.h"
REGISTER_TYPE(RectangleBox)
#include "Engine\UI\Slider\Slider.h"
REGISTER_TYPE(Slider)
#include "Engine\UI\TextField\TextField.h"
REGISTER_TYPE(TextField)
#include "Engine\UI\Toggle\Toggle.h"
REGISTER_TYPE(Toggle)
using namespace Engine::Window;

#include "Engine\Window\Engine\EngineWindow.h"
REGISTER_TYPE(EngineWindow)
using namespace Test;

#include "Test\A\A.h"
REGISTER_TYPE(A)
#include "Test\Component\PlayerComponent.h"
REGISTER_TYPE(PlayerComponent)
#include "Test\PrimaryType\Integer\IntegerTest.h"
REGISTER_TYPE(IntegerTest)

