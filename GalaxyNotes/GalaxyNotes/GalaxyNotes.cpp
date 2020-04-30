// GalaxyNotes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DateTime.h"
#include "Note.h"
#include "Star.h"
#include "StarFactory.h"

using namespace std;

int main() {
	StarFactory *star_factory = new StarFactory();
	Star* star1 = star_factory->getStarType(Type::NOTE);
	cout << "Initial title: " << star1->getStarTitle() << "\n";
	star1->createStar("A note");
	cout << star1->getStarTitle();

	Star* star2 = star_factory->getStarType(Type::GROCERY_LIST);
	cout << "Initial title: " << star2->getStarTitle() << "\n";
	star2->createStar("A grocery list");
	cout << star2->getStarTitle();

	Star* star3 = star_factory->getStarType(Type::REMINDER);
	cout << "Initial title: " << star3->getStarTitle() << "\n";
	star3->createStar("A reminder");
	cout << star3->getStarTitle();

	Star* star4 = star_factory->getStarType(Type::TODO_LIST);
	cout << "Initial title: " << star4->getStarTitle() << "\n";
	star4->createStar("ToDo");
	cout << star4->getStarTitle();

	delete star4;
	delete star3;
	delete star2;
	delete star1;
	delete star_factory;
	return 0;
}