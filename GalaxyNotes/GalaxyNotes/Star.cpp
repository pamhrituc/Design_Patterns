#include "Star.h"



Star::Star()
{
}

bool Star::add(StarList * star)
{
	while (star_lists->hasNext())
	{
		if (star_lists->current()->getStarTitle() == star->getStarTitle())
		{
			return false;
		}
		star_lists->next();
	}
	star_lists->goToStart();
	star_lists->stars.push_back(star);
	return true;
}

void Star::quit()
{
	std::string answer;
	std::cout << "Are you sure you want to exit (Y/N)? You may have unchanged stars...\n";
	std::cin >> answer;
	std::transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
	if (answer == "YES" || answer == "Y")
	{
		std::cout << "Bye!\n";
		exit(0);
	}
	if (answer == "NO" || answer == "N")
	{
		std::cout << "Ok! So you have chosen to expand your galaxy.\n";
	}
	else
	{
		std::cout << "Pretty sure that wasn't an option...\n";
		std::cout << "Let's try again.\n";
		quit();
	}
}

void Star::save()
{
	std::ofstream outfile;
	outfile.open("Galaxy.txt");
	unsigned int i = 0;
	while (star_lists->hasNext())
	{
		outfile << star_lists->current()->getDateCreated().hour << ":" << star_lists->current()->getDateCreated().minute << 
			"," << star_lists->current()->getDateCreated().day << "/" << star_lists->current()->getDateCreated().month <<
			"/" << star_lists->current()->getDateCreated().year << "|" << star_lists->current()->getStarTitle() << 
			"|" << "|" << star_lists->current()->getDateCreated().hour << 
			":" << star_lists->current()->getDateCreated().minute << "," << star_lists->current()->getDateCreated().day << 
			"/" << star_lists->current()->getDateCreated().month << "/" << star_lists->current()->getDateCreated().year << "\n";
			star_lists->next();
	}
	outfile.close();
}


Star::~Star()
{
}
