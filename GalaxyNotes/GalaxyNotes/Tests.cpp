#include "Tests.h"

void runTests()
{
	DateTime* today = new DateTime(2, 33, 4, 5, 2020);

	Item* item1 = new Item("Item 1");
	Item* item2 = new Item("Item 2");
	Item* item3 = new Item("Item 3");

	std::vector<Item> items;
	assert(items.size() == 0);

	StarListFactory *star_list_factory = new StarListFactory();

	StarList* star_list1 = star_list_factory->getStarListType(Type::GROCERY_LIST);
	star_list1->createStar(*today, "A grocery list");
	star_list1->addItemToStarList(*item1);

	assert(star_list1->getDateCreated().day == 4);
	assert(star_list1->getDateModified().hour == 2);
	assert(star_list1->getStarTitle() == "A grocery list");
	assert(star_list1->getStarContent().size() == 1);

	StarList* star_list2 = star_list_factory->getStarListType(Type::TODO_LIST);
	star_list2->createStar(*today, "ToDo");
	star_list2->addItemToStarList(*item1);
	star_list2->addItemToStarList(*item2);

	assert(star_list2->getDateCreated().day == 4);
	assert(star_list2->getDateModified().month == 5);
	assert(star_list2->getStarTitle() == "ToDo");
	assert(star_list2->getStarContent().size() == 2);

	StarList* star_list3 = star_list_factory->getStarListType(Type::LUGGAGE_LIST);
	star_list3->createStar(*today, "Luggage 1");
	star_list3->addItemToStarList(*item1);
	star_list3->addItemToStarList(*item2);
	star_list3->addItemToStarList(*item3);

	assert(star_list3->getDateCreated().year == 2020);
	assert(star_list3->getStarTitle() == "Luggage 1");
	assert(star_list3->getStarContent().size() == 3);

	StarListIterator* star_lists = new StarListIterator();
	star_lists->stars.push_back(star_list1);
	star_lists->stars.push_back(star_list2);
	star_lists->stars.push_back(star_list3);
	assert(star_lists->hasNext() == true);
	assert(star_lists->next()->getStarTitle() == "A grocery list");

	delete star_lists;
	delete star_list3;
	delete star_list2;
	delete star_list1;
	delete star_list_factory;
	delete item3;
	delete item2;
	delete item1;
}