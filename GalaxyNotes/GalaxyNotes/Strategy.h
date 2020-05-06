#pragma once
#include <string>
class Strategy
{
public:
	Strategy();
	virtual void order(std::string how) = 0;
	~Strategy();
};

