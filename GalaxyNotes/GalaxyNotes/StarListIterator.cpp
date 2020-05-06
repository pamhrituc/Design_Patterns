#include "StarListIterator.h"



StarListIterator::StarListIterator()
{
}

bool StarListIterator::hasNext()
{
	return index < stars.size();
}

StarList* StarListIterator::next()
{
	if (this->hasNext())
	{
		return this->stars.at(index);
	}
	return nullptr;
}

StarList * StarListIterator::current()
{
	if (index < stars.size())
	{
		return stars.at(index);
	}
	return nullptr;
}

void StarListIterator::goToStart()
{
	index = 0;
}


StarListIterator::~StarListIterator()
{
}
