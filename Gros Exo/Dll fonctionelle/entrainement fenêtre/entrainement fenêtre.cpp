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
#include "ComplexShape.h"


using namespace Core::PrimitiveType;
using namespace Core;
using namespace Core::IO;

int main()
{
    Window window = Window("Test", 1000, 800);
    window.Register(new CircleShape({ 56,200 }, 500));
    std::vector<Gdiplus::PointF> _points = std::vector<Gdiplus::PointF>(120);
    window.Register(new ComplexShape(_points));
    window.Open();
    return 0;
}

