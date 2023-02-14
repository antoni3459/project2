#include "Transform.h"


Engine::Transform::Transform(const Transform& _copy) : super(_copy)
{
	position = _copy.position;
}
