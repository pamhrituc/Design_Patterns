#include "Note.h"
#include <iostream>

using namespace std;

Note::Note()
{
}

void Note::createStar(std::string note_title)
{
	this->note_title = note_title;
	//this->note_content = note_content;
	cout << "Note with title: " + note_title + " has been created.\n";
}

DateTime Note::getDateCreated() const
{
	return this->date_created;
}

DateTime Note::getDateModified() const
{
	return this->date_modified;
}

std::string Note::getStarTitle() const
{
	return this->note_title;
}

std::string Note::getNoteContent() const
{
	return this->note_content;
}

Note::~Note()
{
}
