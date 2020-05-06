#pragma once
#include "StarList.h"

template <typename T>
class Iterator
{
public:
	int index = 0;
	std::vector<T> list;

	Iterator() {}
	virtual bool hasNext() = 0;
	virtual T next() = 0;
	~Iterator() {}
};
