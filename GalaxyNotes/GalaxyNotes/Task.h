#pragma once
#include <string>
#include <vector>

class Task
{
private:
	std::string task_name;
	bool is_task_completed;
	std::vector<Task> sub_task_list;
public:
	Task();
	Task(std::string task_name) : task_name(task_name), is_task_completed(false) {}
	std::string getTaskName() const;
	void setTaskName(std::string task_name);
	bool isTaskCompleted() const;
	void setIsTaskCompleted(bool task_completed);
	std::vector<Task> getSubTaskList();
	void addAsSubTask(Task task);
	~Task();
};

