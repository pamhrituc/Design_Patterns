#pragma once
#include"Iterator.h"
class Container
{
public:
	Container();
	virtual Iterator getIterator() = 0;
	~Container();
};

