#pragma once
#include <string>
#include <vector>
#include "StarList.h"

class ToDoList : public StarList
{
private:
	DateTime date_created;
	DateTime date_modified;
	std::string todo_title;
	std::vector<Item> todo_list;
	//std::vector<Task> todo_list;
public:
	ToDoList();
	void createStar(DateTime date_created, std::string star_title) override;
	DateTime getDateCreated() const override;
	DateTime getDateModified() const override;
	std::string getStarTitle() const override;
	std::vector<Item> getStarContent() const override;
	void setDateCreated(DateTime* date_created) override;
	void setDateModified(DateTime* date_modified) override;
	void setStarTitle(std::string star_title) override;
	void addItemToStarList(Item item);
	~ToDoList();
};

