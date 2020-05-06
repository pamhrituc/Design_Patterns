#include <iostream>
#include "GroceryList.h"

GroceryList::GroceryList()
{
}

void GroceryList::createStar(DateTime date_created, std::string star_title)
{
	this->date_created = date_created;
	this->date_modified = date_created;
	this->grocery_title = star_title;
}

DateTime GroceryList::getDateCreated() const
{
	return this->date_created;
}

DateTime GroceryList::getDateModified() const
{
	return this->date_modified;
}

std::string GroceryList::getStarTitle() const
{
	return this->grocery_title;
}

std::vector<Item> GroceryList::getStarContent() const
{
	return this->grocery_list_content;
}

void GroceryList::addItemToStarList(Item item)
{
	this->grocery_list_content.push_back(item);
}

void GroceryList::setDateCreated(DateTime * date_created)
{
	this->date_created.minute = date_created->minute;
	this->date_created.hour = date_created->hour;
	this->date_created.day = date_created->day;
	this->date_created.month = date_created->month;
	this->date_created.year = date_created->year;
}

void GroceryList::setDateModified(DateTime * date_modified)
{
	this->date_modified.minute = date_modified->minute;
	this->date_modified.hour = date_modified->hour;
	this->date_modified.day = date_modified->day;
	this->date_modified.month = date_modified->month;
	this->date_modified.year = date_modified->year;
}

void GroceryList::setStarTitle(std::string star_title)
{
	this->grocery_title = star_title;
}

GroceryList::~GroceryList()
{
}
