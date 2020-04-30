#pragma once
#include <string>
#include "GroceryList.h"
#include "Note.h"
#include "Reminder.h"
#include "Star.h"
#include "ToDoList.h"
#include "Types.h"

class StarFactory {
public:
	StarFactory();
	Star* getStarType(Type type);
	~StarFactory();
};