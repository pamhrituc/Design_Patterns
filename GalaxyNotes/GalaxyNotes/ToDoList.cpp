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

void ToDoList::setDateCreated(DateTime * date_created)
{
	this->date_created.minute = date_created->minute;
	this->date_created.hour = date_created->hour;
	this->date_created.day = date_created->day;
	this->date_created.month = date_created->month;
	this->date_created.year = date_created->year;
}

void ToDoList::setDateModified(DateTime * date_modified)
{
	this->date_modified.minute = date_modified->minute;
	this->date_modified.hour = date_modified->hour;
	this->date_modified.day = date_modified->day;
	this->date_modified.month = date_modified->month;
	this->date_modified.year = date_modified->year;
}

void ToDoList::setStarTitle(std::string star_title)
{
	this->todo_title = star_title;
}

void ToDoList::addItemToStarList(Item item)
{
	this->todo_list.push_back(item);
}


ToDoList::~ToDoList()
{
}
