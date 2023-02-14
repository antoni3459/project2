#include "Selection.h"

#pragma region method
void Engine::Selection::SetSelection(Object* _obj)
{
    if (selected == _obj)return;
    selected = _obj;
    OnSelectionGhanged.Invoke(selected);
}

Engine::Object* Engine::Selection::GetSelected()
{
    return selected;
}
#pragma endregion method