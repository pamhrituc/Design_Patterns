#pragma once
#include <vector>
#include "Iterator.h"
#include "StarList.h"

class StarListIterator : public Iterator<StarList*>
{
public:
	std::vector<StarList*> stars;
	unsigned int index = 0;
	StarListIterator();
	bool hasNext() override;
	StarList* next() override;
	StarList* current() override;
	void goToStart() override;
	~StarListIterator();
};

