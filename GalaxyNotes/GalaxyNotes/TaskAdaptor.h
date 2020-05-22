#pragma once
#include "Item.h"
#include "Task.h"
class TaskAdaptor : public Item
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

