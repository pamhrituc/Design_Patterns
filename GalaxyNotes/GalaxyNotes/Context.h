#pragma once
#include "Strategy.h"
class Context
{
private:
	Strategy* strategy;
public:
	Context();
	Context(Strategy* strategy) : strategy(strategy) {}
	StarListIterator* executeStrategy(std::string how, StarListIterator* star_list_iterator);
	~Context();
};