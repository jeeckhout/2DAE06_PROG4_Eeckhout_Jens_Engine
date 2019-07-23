#include "pch.h"
#include "StopAttackCommand.h"


StopAttackCommand::StopAttackCommand()
{
}


StopAttackCommand::~StopAttackCommand()
{
}

void StopAttackCommand::Execute(dae::GameObject* object, ObjectType, const float &)
{
		object->DeleteChildren();
}
