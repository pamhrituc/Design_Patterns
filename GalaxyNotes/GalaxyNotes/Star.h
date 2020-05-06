#pragma once
#include "StarList.h"
#include "StarListIterator.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Types.h"
class Star
{
public:
	StarListIterator* star_lists = new StarListIterator();
	Star();
	bool add(StarList* star);
	bool remove(StarList* star);
	void quit();
	void help();
	void save();
	void view(StarList* star);
	void update(StarList* old_star, StarList* new_star);
	void filter(Type type);
	void viewAll();
	~Star();
};

