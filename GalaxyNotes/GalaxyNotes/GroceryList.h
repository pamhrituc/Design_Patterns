#pragma once
#include <map>
#include <string>
#include "DateTime.h"
#include "Star.h"

class GroceryList : public Star
{
private:
	DateTime date_created;
	DateTime date_modified;
	std::string grocery_title;
	std::map<std::string, int> grocery_list;
public:
	GroceryList();
	void createStar(std::string grocery_title) override;
	DateTime getDateCreated() const override;
	DateTime getDateModified() const override;
	std::string getStarTitle() const override;
	std::map<std::string, int> getGroceryList() const;
	~GroceryList();
};

