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

void LuggageList::setDateCreated(DateTime * date_created)
{
	this->date_created.minute = date_created->minute;
	this->date_created.hour = date_created->hour;
	this->date_created.day = date_created->day;
	this->date_created.month = date_created->month;
	this->date_created.year = date_created->year;
}

void LuggageList::setDateModified(DateTime * date_modified)
{
	this->date_modified.minute = date_modified->minute;
	this->date_modified.hour = date_modified->hour;
	this->date_modified.day = date_modified->day;
	this->date_modified.month = date_modified->month;
	this->date_modified.year = date_modified->year;
}

void LuggageList::setStarTitle(std::string star_title)
{
	this->luggage_title = star_title;
}


LuggageList::~LuggageList()
{
}
