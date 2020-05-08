#include "OrderTitle.h"



OrderTitle::OrderTitle()
{
}

StarListIterator* OrderTitle::order(std::string how, StarListIterator * star_list_iterator)
{
	if (how == "DESC")
	{
		std::sort(star_list_iterator->stars.begin(), star_list_iterator->stars.end(), [](const StarList* lhs, const StarList* rhs) {return lhs->getStarTitle() > rhs->getStarTitle(); });
	}
	else
	{
		std::sort(star_list_iterator->stars.begin(), star_list_iterator->stars.end(), [](const StarList* lhs, const StarList* rhs) {return lhs->getStarTitle() < rhs->getStarTitle(); });
	}
	return star_list_iterator;
}


OrderTitle::~OrderTitle()
{
}
