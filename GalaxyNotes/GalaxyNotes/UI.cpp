#include "UI.h"

StarListIterator* load()
{
	std::ostringstream os;
	char ch;
	std::string data;
	/***
	* Here we read from a file
	* TYPE|HH:MM~DD/MM/YYYY~|TITLE|ITEM1;ITEM2;|HH:MM~DD/MM/YYYY\n
	***/
	StarListFactory *star_list_factory = new StarListFactory();
	StarListIterator* star_lists = new StarListIterator();
	std::ifstream infile;
	infile.open("Galaxy.txt");
	while (infile >> std::noskipws >> ch) {
		os << ch;
		data = os.str();
	}
	std::stringstream ss(data);
	std::string token;
	unsigned int i = 0;
	unsigned int current, previous = 0;
	unsigned int minute, hour, day, month, year;
	std::string title;
	DateTime* date_time;
	Item* item = new Item();
	StarList* star_list = star_list_factory->getStarListType(Type::DEFAULT);
	while (std::getline(ss, token, '|')) {
		switch (i % 5)
		{
		case 0:
			if (token == "LUGGAGE")
			{
				star_list = star_list_factory->getStarListType(Type::LUGGAGE_LIST);
			}
			if (token == "GROCERY")
			{
				star_list = star_list_factory->getStarListType(Type::GROCERY_LIST);
			}
			if (token == "TODO")
			{
				star_list = star_list_factory->getStarListType(Type::TODO_LIST);
			}
			break;
		case 1:
			previous = 0;
			current = token.find(':');
			hour = stoi(token.substr(previous, current - previous));
			previous = current + 1;
			current = token.find('~', previous);
			minute = stoi(token.substr(previous, current - previous));
			previous = current + 1;
			current = token.find('/', previous);
			day = stoi(token.substr(previous, current - previous));
			previous = current + 1;
			current = token.find('/', previous);
			month = stoi(token.substr(previous, current - previous));
			previous = current + 1;
			current = token.find('~', previous);
			year = stoi(token.substr(previous, current - previous));
			date_time = new DateTime(minute, hour, day, month, year);
			star_list->setDateCreated(date_time);
			break;
		case 2:
			star_list->setStarTitle(token);
			std::cout << "WhOOP\n";
			std::cout << token << "\n";
			std::cout << star_list->getStarTitle() << "\n";
			break;
		case 3:
			std::cout << "Items: " << token << "\n";
			previous = 0;
			current = token.find(';');
			while (current != std::string::npos)
			{
				item = new Item(token.substr(previous, current - previous));
				if (token.substr(previous, current - previous).find('*') != std::string::npos)
				{
					item->setItemName(token.substr(previous, current - previous).erase(token.substr(previous, current - previous).find('*')));
					item->setIsItemChecked(true);
				}
				star_list->addItemToStarList(*item);
				previous = current + 1;
				current = token.find(';', previous);
				std::cout << item->getItemName() << "\n";
			}
			break;			
		case 4:
			previous = 0;
			current = token.find(':');
			hour = stoi(token.substr(previous, current - previous));
			previous = current + 1;
			current = token.find('~', previous);
			minute = stoi(token.substr(previous, current - previous));
			previous = current + 1;
			current = token.find('/', previous);
			day = stoi(token.substr(previous, current - previous));
			previous = current + 1;
			current = token.find('/', previous);
			month = stoi(token.substr(previous, current - previous));
			previous = current + 1;
			current = token.find('~', previous);
			year = stoi(token.substr(previous, current - previous));
			date_time = new DateTime(minute, hour, day, month, year);
			star_list->setDateModified(date_time);
			star_lists->stars.push_back(star_list);

			break;
		}
		i++;
	}

	infile.close();
	return star_lists;
}

void help()
{
	std::cout << "So, you've decided you need help.\n";
	std::cout << "You've come to the right place.\n";
	std::cout << "Here's the list of commands.\n";
	std::cout << "\t ADD <star_type>\n";
	std::cout << "\t\t Allows you to expand your galaxy by adding a star.\n";
	std::cout << "\t\t Star types include Grocery list, luggage list and todo list.\n";
	std::cout << "\t\t For grocery type in groc.\n";
	std::cout << "\t\t For luggage type in lugg.\n";
	std::cout << "\t\t For todo type in td.\n";
	std::cout << "\n";
	std::cout << "\t HELP.\n";
	std::cout << "\t\t You're here. I'm pretty sure that's the command you used to get here.\n";
	std::cout << "\n";
	std::cout << "\t QUIT.\n";
	std::cout << "\t\t The command to use when you wanna get out of this galaxy and do something else.\n";
	std::cout << "\n";
	std::cout << "\t SAVE.\n";
	std::cout << "\t\t Saves all modifications to a file. You better be sure about this. No takebacks.\n";
	std::cout << "\n";
	std::cout << "\t FILTER <star_type>\n";
	std::cout << "\t\t Allows you to view star types of your choice.\n";
	std::cout << "\t\t Star types include Grocery list, luggage list and todo list.\n";
	std::cout << "\t\t For grocery type in groc.\n";
	std::cout << "\t\t For luggage type in lugg.\n";
	std::cout << "\t\t For todo type in td.\n";
	std::cout << "\n";
}

void show(StarListIterator* star_lists)
{
	unsigned int i = 0;
	for (i = 0; i < star_lists->stars.size(); i++)
	{
		std::cout << "Title: " << star_lists->stars.at(i)->getStarTitle() << "\n";
		std::cout << "Created on: " << star_lists->stars.at(i)->getDateCreated().day << "/" <<
			star_lists->stars.at(i)->getDateCreated().month << "/" << star_lists->stars.at(i)->getDateCreated().year << "\n";
		for (unsigned int j = 0; j < star_lists->stars.at(i)->getStarContent().size(); j++)
		{
			if (star_lists->stars.at(i)->getStarContent().at(j).getIsItemChecked())
			{
				std::cout << "\t[X] " << star_lists->stars.at(i)->getStarContent().at(j).getItemName() << "\n";
			}
			else
			{
				std::cout << "\t[] " << star_lists->stars.at(i)->getStarContent().at(j).getItemName() << "\n";
			}
		}
	}
}

void save(StarListIterator* star_lists)
{
	std::ofstream outfile;
	outfile.open("Galaxy.txt");
	unsigned int i = 0;
	star_lists->goToStart();
	while (star_lists->hasNext())
	{
		if (GroceryList* groc_list = dynamic_cast<GroceryList*>(star_lists->current()))
		{
			outfile << "GROCERY";
		}
		if (LuggageList* lugg_list = dynamic_cast<LuggageList*>(star_lists->current()))
		{
			outfile << "LUGGAGE";
		}
		if (ToDoList* todo_list = dynamic_cast<ToDoList*>(star_lists->current()))
		{
			outfile << "TODO";
		}
		outfile << star_lists->current()->getDateCreated().hour << ":" << star_lists->current()->getDateCreated().minute << "~" <<
			star_lists->current()->getDateCreated().day << "/" << star_lists->current()->getDateCreated().minute << "/" <<
			star_lists->current()->getDateCreated().year << "~|" << star_lists->current()->getStarTitle() << "|";
		for (unsigned int j = 0; j < star_lists->current()->getStarContent().size(); j++)
		{
			outfile << star_lists->current()->getStarContent().at(j).getItemName();
			if (star_lists->current()->getStarContent().at(j).getIsItemChecked())
			{
				outfile << "*";
			}
			outfile << "|" << star_lists->current()->getDateCreated().hour << ":" <<
				star_lists->current()->getDateCreated().minute << "~" << star_lists->current()->getDateCreated().day << "/" <<
				star_lists->current()->getDateCreated().month << "/" << star_lists->current()->getDateCreated().year << "~|";
		}
		star_lists->next();
	}
	star_lists->goToStart();
	outfile.close();
}

void view(StarListIterator* star_lists)
{
	std::string star_title;
	std::cout << "Care to mention the title of the star you're looking for?\n";
	std::cin.getline(star_title, 10);
	std::cout << star_title;
	unsigned int i = 0;
	for (i = 0; i < star_lists->stars.size(); i++)
	{
		if (star_lists->current()->getStarTitle() == star_title)
		{
			std::cout << "Found it!\n";
			std::cout << "Here's your note\n";
			std::cout << "Title: " << star_lists->stars.at(i)->getStarTitle() << "\n";
			std::cout << "Created on: " << star_lists->stars.at(i)->getDateCreated().day << "/" <<
				star_lists->stars.at(i)->getDateCreated().month << "/" << star_lists->stars.at(i)->getDateCreated().year << "\n";
			for (unsigned int j = 0; j < star_lists->stars.at(i)->getStarContent().size(); j++)
			{
				if (star_lists->stars.at(i)->getStarContent().at(j).getIsItemChecked())
				{
					std::cout << "\t[X] " << star_lists->stars.at(i)->getStarContent().at(j).getItemName() << "\n";
				}
				else
				{
					std::cout << "\t[] " << star_lists->stars.at(i)->getStarContent().at(j).getItemName() << "\n";
				}
			}
			return;
		}
	}
	std::cout << "Couldn't find your star, sorry.\n";
	std::cout << "Maybe try creating it?\n";
}

void ui()
{
	StarListIterator* star_lists = load();
	std::string command;

	std::cout << "Welcome to Galaxy Lists, your list handling app.\n";
	std::cout << "What can I do for you?\n";
	std::cout << "Type HELP, for help.\n";

	while (true)
	{
		std::cin >> command;
		if (command == "ADD") 
		{

		}
		else if (command == "EXIT")
		{
			return;
		}
		else if (command == "FILTER")
		{

		}
		else if (command == "HELP")
		{
			help();
		}
		else if (command == "ORDER")
		{

		}
		else if (command == "SAVE")
		{
			save(star_lists);
		}
		else if (command == "SHOW")
		{
			show(star_lists);
		}
		else if (command == "VIEW")
		{
			view(star_lists);
		}
		else
		{
			std::cout << "Command doesn't exist!\n";
			std::cout << "Let's try that again, shall we?\n";
		}
	}
}
