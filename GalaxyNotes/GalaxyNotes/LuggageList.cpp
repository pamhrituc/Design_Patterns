#include "LuggageList.h"



LuggageList::LuggageList()
{
}

void LuggageList::createStar(DateTime date_created, std::string star_title)
{
	this->date_created = date_created;
	this->date_modified = date_created;
	this->luggage_title = star_title;
}

DateTime LuggageList::getDateCreated() const
{
	return this->date_created;
}

DateTime LuggageList::getDateModified() const
{
	return this->date_modified;
}

std::string LuggageList::getStarTitle() const
{
	return this->luggage_title;
}

std::vector<Item> LuggageList::getStarContent() const
{
	return this->luggage_list_content;
}

void LuggageList::addItemToStarList(Item item)
{
	this->luggage_list_content.push_back(item);
}


LuggageList::~LuggageList()
{
}
