#include "Context.h"



Context::Context()
{
}


StarListIterator* Context::executeStrategy(std::string how, StarListIterator * star_list_iterator)
{
	return strategy->order(how, star_list_iterator);
}

Context::~Context()
{
}
