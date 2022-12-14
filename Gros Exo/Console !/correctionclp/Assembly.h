#pragma once
#include "Domain/AppDomain.h"
#include "Command/CD/CdCommand.h"
REGISTER_CLASS(CdCommand)
#include "Command/Cls/ClsCommand.h"
REGISTER_CLASS(ClsCommand)
#include "Command/Drive/DrivesCommand.h"
REGISTER_CLASS(DrivesCommand)
#include "Command/EchoCommand/EchoCommand.h"
REGISTER_CLASS(EchoCommand)
#include "Command/Exit/ExitCommand.h"
REGISTER_CLASS(ExitCommand)
#include "Command/TaskList/TaskListCommand.h"
REGISTER_CLASS(TaskListCommand)
#include "Command/Time/TimeCommand.h"
REGISTER_CLASS(TimeCommand)
#include "Command/Tree/TreeCommand.h"
REGISTER_CLASS(TreeCommand)
#include "Command/Type/TypeCommand.h"
REGISTER_CLASS(TypeCommand)
#include "Object/Object.h"
REGISTER_CLASS(Object)

