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


using namespace Core::PrimitiveType;
using namespace Core;
using namespace Core::IO;

int main()
{
    Window window = Window("Test", 1000, 800);
   
    RectangleShape shape1 = RectangleShape({ 50,180 }, 100, 40);

    CircleShape shape = CircleShape({ 50,20 }, 100);
    window.Open();
    return 0;
}

