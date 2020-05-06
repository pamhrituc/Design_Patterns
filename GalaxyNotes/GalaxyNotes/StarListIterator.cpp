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


StarListIterator::~StarListIterator()
{
}
