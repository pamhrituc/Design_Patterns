#include <iostream>
#include "GroceryList.h"

GroceryList::GroceryList()
{
}

void GroceryList::createStar(std::string grocery_title)
{
	this->grocery_title = grocery_title;
	std::cout << "A grocery list with the title: " + this->grocery_title + " has been created.";
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

std::map<std::string, int> GroceryList::getGroceryList() const
{
	return this->grocery_list;
}


GroceryList::~GroceryList()
{
}
