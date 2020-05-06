#include <iostream>
#include "ToDoList.h"

ToDoList::ToDoList()
{
}

void ToDoList::createStar(DateTime date_created, std::string star_title)
{
	this->date_created = date_created;
	this->date_modified = date_created;
	this->todo_title = star_title;
}

DateTime ToDoList::getDateCreated() const
{
	return this->date_created;
}

DateTime ToDoList::getDateModified() const
{
	return this->date_modified;
}

std::string ToDoList::getStarTitle() const
{
	return this->todo_title;
}

std::vector<Item> ToDoList::getStarContent() const
{
	return this->todo_list;
}

void ToDoList::addItemToStarList(Item item)
{
	this->todo_list.push_back(item);
}


ToDoList::~ToDoList()
{
}
