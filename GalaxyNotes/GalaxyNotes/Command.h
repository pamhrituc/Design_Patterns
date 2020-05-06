#pragma once
class Command
{
public:
	Command() {}
	virtual void execute() = 0;
	virtual void executeWParam(StarList* star_list) = 0;
	~Command() {}
};

