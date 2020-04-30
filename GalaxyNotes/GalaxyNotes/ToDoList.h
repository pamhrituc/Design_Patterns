#pragma once
#include <string>
#include <vector>
#include "Star.h"

class ToDoList : public Star
{
private:
	DateTime date_created;
	DateTime date_modified;
	std::string todo_title;
	std::vector<std::string> todo_list;
public:
	ToDoList();
	void createStar(std::string todo_title) override;
	DateTime getDateCreated() const override;
	DateTime getDateModified() const override;
	std::string getStarTitle() const override;
	std::vector<std::string> getToDoList() const;
	~ToDoList();
};

