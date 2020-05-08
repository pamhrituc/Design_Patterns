#include "OrderCreatedDate.h"



OrderCreatedDate::OrderCreatedDate()
{
}

StarListIterator* OrderCreatedDate::order(std::string how, StarListIterator * star_list_iterator)
{
	if (how == "DESC")
	{
		std::sort(star_list_iterator->stars.begin(), star_list_iterator->stars.end(), [](const StarList* lhs, const StarList* rhs) 
		{
			return lhs->getDateCreated().year > rhs->getDateCreated().year ||
				lhs->getDateCreated().year == rhs->getDateCreated().year && 
				lhs->getDateCreated().month > rhs->getDateCreated().month || 
				lhs->getDateCreated().year == rhs->getDateCreated().year && 
				lhs->getDateCreated().month == rhs->getDateCreated().month &&
				lhs->getDateCreated().day > rhs->getDateCreated().day || 
				lhs->getDateCreated().year == rhs->getDateCreated().year && 
				lhs->getDateCreated().month == rhs->getDateCreated().month && 
				lhs->getDateCreated().day == rhs->getDateCreated().day &&
				lhs->getDateCreated().hour > rhs->getDateCreated().hour ||
				lhs->getDateCreated().year == rhs->getDateCreated().year &&
				lhs->getDateCreated().month == rhs->getDateCreated().month &&
				lhs->getDateCreated().day == rhs->getDateCreated().day &&
				lhs->getDateCreated().hour == rhs->getDateCreated().hour &&
				lhs->getDateCreated().minute > rhs->getDateCreated().minute;
		});
	}
	else
	{
		std::sort(star_list_iterator->stars.begin(), star_list_iterator->stars.end(), [](const StarList* lhs, const StarList* rhs) 
		{
			return lhs->getDateCreated().year < rhs->getDateCreated().year ||
				lhs->getDateCreated().year == rhs->getDateCreated().year &&
				lhs->getDateCreated().month < rhs->getDateCreated().month ||
				lhs->getDateCreated().year == rhs->getDateCreated().year &&
				lhs->getDateCreated().month == rhs->getDateCreated().month &&
				lhs->getDateCreated().day < rhs->getDateCreated().day ||
				lhs->getDateCreated().year == rhs->getDateCreated().year &&
				lhs->getDateCreated().month == rhs->getDateCreated().month &&
				lhs->getDateCreated().day == rhs->getDateCreated().day &&
				lhs->getDateCreated().hour < rhs->getDateCreated().hour ||
				lhs->getDateCreated().year == rhs->getDateCreated().year &&
				lhs->getDateCreated().month == rhs->getDateCreated().month &&
				lhs->getDateCreated().day == rhs->getDateCreated().day &&
				lhs->getDateCreated().hour == rhs->getDateCreated().hour &&
				lhs->getDateCreated().minute < rhs->getDateCreated().minute;
		});
	}
	return star_list_iterator;
}


OrderCreatedDate::~OrderCreatedDate()
{
}
