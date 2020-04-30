#pragma once
#include <string>
#include "DateTime.h"

class Star {
protected:
	DateTime date_created;
	DateTime date_modified;
	std::string star_title;
public:
	virtual ~Star() {};
	virtual void createStar(std::string star_title) = 0;
	virtual DateTime getDateCreated() const = 0;
	virtual DateTime getDateModified() const = 0;
	virtual std::string getStarTitle() const = 0;
};