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

GroceryList::~GroceryList()
{
}
