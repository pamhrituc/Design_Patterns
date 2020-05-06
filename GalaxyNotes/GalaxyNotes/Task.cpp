#include "Task.h"



Task::Task()
{
}

std::string Task::getTaskName() const
{
	return this->task_name;
}

void Task::setTaskName(std::string task_name)
{
	this->task_name = task_name;
}

bool Task::isTaskCompleted() const
{
	return this->is_task_completed;
}

void Task::setIsTaskCompleted(bool task_completed)
{
	this->is_task_completed = task_completed;
}

std::vector<Task> Task::getSubTaskList()
{
	return this->sub_task_list;
}

void Task::addAsSubTask(Task task)
{
	this->sub_task_list.push_back(task);
}

Task::~Task()
{
}
