#include "StarFactory.h"

StarFactory::StarFactory()
{
}

Star* StarFactory::getStarType(Type type)
{
	if (type == GROCERY_LIST)
	{
		return new GroceryList();
	}
	if (type == NOTE)
	{
		return new Note();
	}
	if (type == REMINDER)
	{
		return new Reminder();
	}
	if (type == TODO_LIST)
	{
		return new ToDoList();
	}
}

StarFactory::~StarFactory()
{
}

