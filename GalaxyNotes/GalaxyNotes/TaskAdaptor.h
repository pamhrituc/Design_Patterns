#pragma once
#include "Task.h"
class TaskAdaptor
{
private:
	Task item;
public:
	TaskAdaptor();
	TaskAdaptor(Task task);
	std::string getItemName();
	bool getIsItemChecked();
	~TaskAdaptor();
};

