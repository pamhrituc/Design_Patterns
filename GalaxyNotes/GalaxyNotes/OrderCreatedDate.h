#pragma once
#include <algorithm>
#include "Strategy.h"

class OrderCreatedDate : public Strategy
{
public:
	OrderCreatedDate();
	StarListIterator* order(std::string how, StarListIterator* star_list_iterator) override;
	~OrderCreatedDate();
};

