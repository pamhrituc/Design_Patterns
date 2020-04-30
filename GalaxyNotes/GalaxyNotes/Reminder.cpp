#include <iostream>
#include "Reminder.h"

Reminder::Reminder()
{
}

void Reminder::createStar(std::string reminder_title)
{
	this->reminder_title = reminder_title;
	std::cout << "A reminder with the title: " << this->reminder_title << " has been created.\n";
}

DateTime Reminder::getDateCreated() const
{
	return this->date_created;
}

DateTime Reminder::getDateModified() const
{
	return this->date_modified;
}

std::string Reminder::getStarTitle() const
{
	return this->reminder_title;
}

DateTime Reminder::getReminderDate() const
{
	return this->reminder_date;
}


Reminder::~Reminder()
{
}
