#include <iostream>
#include "ToDoList.h"

ToDoList::ToDoList()
{
}

void ToDoList::createStar(std::string todo_title)
{
	this->todo_title = todo_title;
	std::cout << "A ToDo has been created with the title: " << this->todo_title;
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

std::vector<std::string> ToDoList::getToDoList() const
{
	return this->todo_list;
}


ToDoList::~ToDoList()
{
}
