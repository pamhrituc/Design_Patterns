#pragma once
#include <string>
#include "StarListIterator.h"

class Strategy
{
public:
	Strategy() {}
	virtual StarListIterator* order(std::string how, StarListIterator* star_list_iterator) = 0;
	~Strategy() {}
};

