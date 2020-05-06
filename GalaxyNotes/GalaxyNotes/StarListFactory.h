#pragma once
#include <string>
#include "GroceryList.h"
#include "LuggageList.h"
#include "StarList.h"
#include "ToDoList.h"
#include "Types.h"

class StarListFactory {
public:
	StarListFactory();
	StarList* getStarListType(Type type);
	~StarListFactory();
};