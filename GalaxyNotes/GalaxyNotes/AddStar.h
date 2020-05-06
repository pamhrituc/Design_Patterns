#pragma once
#include "Command.h"
#include "Star.h"
#include "StarList.h"
class AddStar : public Command
{
public:
	Star* star;
	AddStar();
	AddStar(Star* star, Type type);
	void execute() override;
	~AddStar();
};

