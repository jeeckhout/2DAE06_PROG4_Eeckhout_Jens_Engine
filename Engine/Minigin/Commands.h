#pragma once
#include <iostream>
#include "Locator.h"

class Command
{
public:
	virtual ~Command() = default;
	virtual void Execute() = 0;
};
