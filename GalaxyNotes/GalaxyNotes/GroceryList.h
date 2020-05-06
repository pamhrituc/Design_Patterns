#pragma once
#include <string>
#include <vector>
#include "DateTime.h"
#include "StarList.h"

class GroceryList : public StarList
{
private:
	DateTime date_created;
	DateTime date_modified;
	std::string grocery_title;
	std::vector<Item> grocery_list_content;
public:
	GroceryList();
	void createStar(DateTime date_created, std::string star_title) override;
	DateTime getDateCreated() const override;
	DateTime getDateModified() const override;
	std::string getStarTitle() const override;
	std::vector<Item> getStarContent() const override;
	void addItemToStarList(Item item);
	~GroceryList();
};

