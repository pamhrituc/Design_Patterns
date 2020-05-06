#pragma once
#include <string>
#include <vector>
#include "DateTime.h"
#include "Item.h"

class StarList {
protected:
	DateTime date_created;
	DateTime date_modified;
	std::string star_title;
	std::vector<Item> star_content;
public:
	virtual void createStar(DateTime date_created, std::string star_title) = 0;
	virtual DateTime getDateCreated() const = 0;
	virtual DateTime getDateModified() const = 0;
	virtual std::string getStarTitle() const = 0;
	virtual std::vector<Item> getStarContent() const = 0;
	virtual void addItemToStarList(Item item) = 0;
	virtual void setDateCreated(DateTime* date_created) = 0;
	virtual void setDateModified(DateTime* date_created) = 0;
	virtual void setStarTitle(std::string star_title) = 0;
	virtual ~StarList() {};
};