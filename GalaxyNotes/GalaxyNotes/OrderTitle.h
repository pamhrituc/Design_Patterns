#pragma once
#include <algorithm>
#include "Strategy.h"
class OrderTitle :
	public Strategy
{
public:
	OrderTitle();
	StarListIterator* order(std::string how, StarListIterator* star_list_iterator);
	~OrderTitle();
};

