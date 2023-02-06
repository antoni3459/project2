#pragma once
#include "Engine/Utils/ObjectMacro.h"
#include "Engine\AssetDataBase\AssetDataBase.h"
REGISTER_TYPE(Engine::AssetDataBase)
#include "Engine\Component\Component.h"
REGISTER_TYPE(Engine::Component)
#include "Engine\Exception\Exception.h"
REGISTER_TYPE(Engine::Exception)
#include "Engine\Manager\GameObject\GameObjectManager.h"
REGISTER_TYPE(Engine::	Window::Engine::Manager::GameObjectManager)
#include "Engine\PrimaryType\Boolean\Boolean.h"
REGISTER_TYPE(Engine::PrimaryType::Boolean)
#include "Engine\PrimaryType\Double\Double.h"
REGISTER_TYPE(Engine::PrimaryType::Double)
#include "Engine\PrimaryType\Enum\Enum.h"
REGISTER_TYPE(Engine::	PrimaryType::Enum)
#include "Engine\PrimaryType\Float\Float.h"
REGISTER_TYPE(Engine::PrimaryType::Float)
#include "Engine\PrimaryType\FString\String.h"
REGISTER_TYPE(Engine::PrimaryType::String)
#include "Engine\PrimaryType\Integer\Integer.h"
REGISTER_TYPE(Engine::PrimaryType::Integer)
#include "Engine\PrimaryType\List\IList.h"
REGISTER_TYPE(Engine::PrimaryType::IList)
#include "Engine\PrimaryType\ValueType\ValueType.h"
REGISTER_TYPE(Engine::	PrimaryType::ValueType)
#include "Engine\PrimaryType\Vector2\Vector2.h"
REGISTER_TYPE(Engine::PrimaryType::Vector2)
#include "Engine\Reflection\Field\FieldInfo.h"
REGISTER_TYPE(Engine::Reflection::FieldInfo)
#include "Engine\Reflection\Flags\BindingFlags.h"
REGISTER_TYPE(BindingFlags)
#include "Engine\Reflection\Function\Function.h"
REGISTER_TYPE(Engine::	PrimaryType::Engine::Reflection::Function)
#include "Engine\Reflection\Function\Parameter\ParameterInfo.h"
REGISTER_TYPE(Engine::Reflection::ParameterInfo)
#include "Engine\Reflection\Utils\ReflectionUtils.h"
REGISTER_TYPE(Engine::Engine::PrimaryType::Engine::Reflection::ReflectionUtils)
#include "Engine\Selection\Selection.h"
REGISTER_TYPE(Engine::Selection)
#include "Engine\Time\Time.h"
REGISTER_TYPE(Engine::Time)
#include "Engine\Transform\Transform.h"
REGISTER_TYPE(Engine::Transform)
#include "Engine\Utils\Console\Console.h"
REGISTER_TYPE(Engine::Utils::Console)
#include "Engine\Utils\Interfarce\Log\ILogger.h"
REGISTER_TYPE(Engine::PrimaryType::Engine::Interfarce::ILogger)
#include "Engine\Window\Engine\EngineWindow.h"
REGISTER_TYPE(Engine::Window::EngineWindow)
#include "Test\Component\PlayerComponent.h"
REGISTER_TYPE(Test::PlayerComponent)
#include "Test\List\ListTest.h"
REGISTER_TYPE(Test::ListTest)
#include "Test\PrimaryType\Double\DoubleTest.h"
REGISTER_TYPE(Test::DoubleTest)
#include "Test\PrimaryType\Float\FloatTest.h"
REGISTER_TYPE(Test::FloatTest)
#include "Test\PrimaryType\Integer\IntegerTest.h"
REGISTER_TYPE(Test::IntegerTest)
#include "Test\Reflection\ReflectionTest.h"
REGISTER_TYPE(Test::ReflectionTest)
#include "Test\Reflection\Json\JsonTest.h"
REGISTER_TYPE(Test::JsonTest)

