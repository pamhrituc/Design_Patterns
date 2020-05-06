#pragma once
#include <iostream>
#include "StarList.h"

class LuggageList : public StarList
{
private:
	DateTime date_created;
	DateTime date_modified;
	std::string luggage_title;
	std::vector<Item> luggage_list_content;
public:
	LuggageList();
	void createStar(DateTime date_created, std::string star_title) override;
	DateTime getDateCreated() const override;
	DateTime getDateModified() const override;
	std::string getStarTitle() const override;
	std::vector<Item> getStarContent() const override;
	void addItemToStarList(Item item) override;
	void setDateCreated(DateTime* date_created) override;
	void setDateModified(DateTime* date_modified) override;
	void setStarTitle(std::string star_title) override;
	~LuggageList();
};

