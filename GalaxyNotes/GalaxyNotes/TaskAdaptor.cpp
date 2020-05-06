#include "TaskAdaptor.h"



TaskAdaptor::TaskAdaptor()
{
}

TaskAdaptor::TaskAdaptor(Task task)
{
	item.setTaskName(task.getTaskName());
	item.setIsTaskCompleted(task.isTaskCompleted());
	unsigned int i;
	for (i = 0; i < task.getSubTaskList().size(); i++)
	{
		item.addAsSubTask(task.getSubTaskList().at(i));
	}
}


TaskAdaptor::~TaskAdaptor()
{
}
