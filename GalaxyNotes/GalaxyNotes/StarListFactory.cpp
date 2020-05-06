#include "StarListFactory.h"

StarListFactory::StarListFactory()
{
}

StarList* StarListFactory::getStarListType(Type type)
{
	if (type == GROCERY_LIST)
	{
		return new GroceryList();
	}
	if (type == LUGGAGE_LIST)
	{
		//return new LuggageList();
		return new LuggageList();
	}
	if (type == TODO_LIST)
	{
		return new ToDoList();
	}
}

StarListFactory::~StarListFactory()
{
}

