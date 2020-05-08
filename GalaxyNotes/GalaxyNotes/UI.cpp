#include "UI.h"

DateTime* getNow()
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:", timeinfo);
	std::string str(buffer);

	unsigned int previous = 0;
	unsigned int current = str.find('-');
	unsigned int day = stoi(str.substr(previous, current - previous));
	previous = current + 1;
	current = str.find('-', previous);
	unsigned int month = stoi(str.substr(previous, current - previous));
	previous = current + 1;
	current = str.find(' ', previous);
	unsigned int year = stoi(str.substr(previous, current - previous));
	previous = current + 1;
	current = str.find(':', previous);
	unsigned int hour = stoi(str.substr(previous, current - previous));
	previous = current + 1;
	current = str.find(':', previous);
	unsigned int minute = stoi(str.substr(previous, current - previous));
	return new DateTime(minute, hour, day, month, year);
}

StarList* add(StarListIterator* star_lists)
{
	DateTime* now = getNow();

	bool ok = false;
	std::string extra;
	std::string type;
	std::string title;
	std::string answer;
	StarListFactory *star_list_factory = new StarListFactory();
	StarList* star_list = star_list_factory->getStarListType(Type::DEFAULT);
	std::vector<Item> items;

	std::cout << "So, you wanna add a star...\n";
	std::cout << "What do you want the star's type to be?\n";
	while (!ok)
	{
		std::cin >> type;
		if (type == "GROCERY")
		{
			star_list = star_list_factory->getStarListType(Type::GROCERY_LIST);
			ok = true;
		}
		else if (type == "LUGGAGE")
		{
			StarList* star_list = star_list_factory->getStarListType(Type::LUGGAGE_LIST);
			ok = true;
		}
		else if (type == "TODO")
		{
			StarList* star_list = star_list_factory->getStarListType(Type::TODO_LIST);
			ok = true;
		}
		else
		{
			std::cout << "Let's try that again\n";
			std::cout << "\tType GROCERY to create a grocery list\n";
			std::cout << "\tType LUGGAGE to create a luggage list\n";
			std::cout << "\tType TODO to create a todo list\n";
		}
	}
	std::cout << "So, what are you naming this star?\n";
	std::getline(std::cin, extra);
	std::getline(std::cin, title);
	while (star_lists->hasNext())
	{
		if (star_lists->current()->getStarTitle() == title)
		{
			std::cout << "Whoops. Seems like you already have a star with that title.\n";
			std::cout << "Maybe try adding a star with a title that's not already in your galaxy.\n";
			star_lists->goToStart();
			return nullptr;
		}
		star_lists->next();
	}
	star_lists->goToStart();
	star_list->createStar(*now, title);
	std::cout << "Care to add any items to it?\n";
	std::cout << "Add as many items as you like. Try not to break the program tho.\n";
	std::cout << "When you're done, just write DONE.\n";
	std::string item_title = "";
	Item* item;
	while (item_title != "DONE")
	{
		std::getline(std::cin, item_title);
		item = new Item(item_title);
		star_list->addItemToStarList(*item);
	}
	return star_list;
}

StarListIterator* check(StarListIterator* star_list_iterator)
{
	std::string extra;
	std::string star_title;
	std::cout << "Care to mention the title of the star you're looking for?\n";
	std::getline(std::cin, extra);
	std::getline(std::cin, star_title);
	std::cout << star_title;

	while (star_list_iterator->hasNext())
	{
		if (star_list_iterator->current()->getStarTitle() == star_title)
		{
			std::cout << "Found it!\n";
			std::cout << "Here's your note\n";
			std::cout << "Title: " << star_list_iterator->current()->getStarTitle() << "\n";
			std::cout << "Created on: " << star_list_iterator->current()->getDateCreated().day << "/" <<
				star_list_iterator->current()->getDateCreated().month << "/" <<
				star_list_iterator->current()->getDateCreated().year << "\n";
			for (unsigned int j = 0; j < star_list_iterator->current()->getStarContent().size(); j++)
			{
				if (star_list_iterator->current()->getStarContent().at(j).getIsItemChecked())
				{
					std::cout << "\t[X] " << star_list_iterator->current()->getStarContent().at(j).getItemName() << "\n";
				}
				else
				{
					std::cout << "\t[] " << star_list_iterator->current()->getStarContent().at(j).getItemName() << "\n";
				}
			}
			unsigned int item_number;
			std::cout << "Which item would you like to check off?\n";
			std::cout << "Give the number of the item off the list.\n";
			std::cin >> item_number;
			star_list_iterator->current()->getStarContent().at(item_number - 1).setIsItemChecked(true);
			return star_list_iterator;
		}
		star_list_iterator->next();
	}
	star_list_iterator->goToStart();
	std::cout << "Couldn't find your star, sorry.\n";
	std::cout << "Maybe try creating it?\n";
	return star_list_iterator;
}

void help()
{
	std::cout << "So, you've decided you need help.\n";
	std::cout << "You've come to the right place.\n";
	std::cout << "Here's the list of commands.\n";
	std::cout << "\t ADD\n";
	std::cout << "\t\t Allows you to expand your galaxy by adding a star.\n";
	std::cout << "\t\t Star types include Grocery list, luggage list and todo list.\n";
	std::cout << "\t\t For grocery type in GROCERY.\n";
	std::cout << "\t\t For luggage type in LUGGAGE.\n";
	std::cout << "\t\t For todo type in TODO.\n";
	std::cout << "\n";
	std::cout << "\t EXIT\n";
	std::cout << "\t\t The command to use when you wanna get out of this galaxy and do something else.\n";
	std::cout << "\n"; 
	std::cout << "\t HELP\n";
	std::cout << "\t\t You're here. I'm pretty sure that's the command you used to get here.\n";
	std::cout << "\n";
	std::cout << "\t ORDER\n";
	std::cout << "\t\t Allows you to order your stars either by creation date, either by title.\n";
	std::cout << "\n";
	std::cout << "\t SAVE\n";
	std::cout << "\t\t Saves all modifications to a file. You better be sure about this. No takebacks.\n";
	std::cout << "\n";
	std::cout << "\t SHOW\n";
	std::cout << "\t\t Shows all your stars.\n";
	std::cout << "\n";
	std::cout << "\t VIEW\n";
	std::cout << "\t\t Allows you to view a star giving its title\n";
}

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

StarListIterator* order(StarListIterator* star_list_iterator)
{
	bool ok = false;
	std::string what = "";
	std::string how = "";
	std::cout << "What would you like to order your stars by?\n";
	std::cout << "\tType TITLE for title\n";
	std::cout << "\tType DATE for creation date\n";
	while (!ok)
	{
		std::cin >> what;
		if (what == "TITLE")
		{
			ok = true;
			Context* context = new Context(new OrderTitle());
			while (true)
			{
				std::cout << "Would you like to order your noted alphabetically or reverse alphabetically?\n";
				std::cout << "\tType ASC for alphabetically.\n";
				std::cout << "\tType DESC for reverse alphabetically.\n";
				std::cin >> how;
				if (how == "ASC")
				{
					context->executeStrategy("ASC", star_list_iterator);
					return star_list_iterator;
				}
				else if (how == "DESC")
				{
					context->executeStrategy("DESC", star_list_iterator);
					return star_list_iterator;
				}
				else
				{
					std::cout << "Let's try that again.\n";
				}
			}
			
		}
		else if (what == "DATE")
		{
			ok = true;
			Context* context = new Context(new OrderCreatedDate());
			while (true)
			{
				std::cout << "Would you like to order your noted chronologically or reverse chronologically?\n";
				std::cout << "\tType ASC for chronologically.\n";
				std::cout << "\tType DESC for reverse chronologically.\n";
				std::cin >> how;
				if (how == "ASC")
				{
					context->executeStrategy("ASC", star_list_iterator);
					return star_list_iterator;
				}
				else if (how == "DESC")
				{
					context->executeStrategy("DESC", star_list_iterator);
					return star_list_iterator;
				}
				else
				{
					std::cout << "Let's try that again.\n";
				}
			}

		}
		else
		{
			std::cout << "Let's try that again.\n";
		}
	}
}

void show(StarListIterator* star_lists)
{
	while (star_lists->hasNext())
	{
		std::cout << "Title: " << star_lists->current()->getStarTitle() << "\n";
		std::cout << "Created on: " << star_lists->current()->getDateCreated().day << "/" <<
			star_lists->current()->getDateCreated().month << "/" << star_lists->current()->getDateCreated().year << "\n";
		for (unsigned int j = 0; j < star_lists->current()->getStarContent().size(); j++)
		{
			if (star_lists->current()->getStarContent().at(j).getIsItemChecked())
			{
				std::cout << "\t[X] " << star_lists->current()->getStarContent().at(j).getItemName() << "\n";
			}
			else
			{
				std::cout << "\t[] " << star_lists->current()->getStarContent().at(j).getItemName() << "\n";
			}
		}
		star_lists->next();
	}
	star_lists->goToStart();
}

void save(StarListIterator* star_lists)
{
	std::cout << "Saving...\n";
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
		outfile << "|" << star_lists->current()->getDateCreated().hour << ":" << star_lists->current()->getDateCreated().minute << "~" <<
			star_lists->current()->getDateCreated().day << "/" << star_lists->current()->getDateCreated().month << "/" <<
			star_lists->current()->getDateCreated().year << "~|" << star_lists->current()->getStarTitle() << "|";
		for (unsigned int j = 0; j < star_lists->current()->getStarContent().size(); j++)
		{
			outfile << star_lists->current()->getStarContent().at(j).getItemName();
			if (star_lists->current()->getStarContent().at(j).getIsItemChecked())
			{
				outfile << "*";
			}
			outfile << ";";
		}
		outfile << "|" << star_lists->current()->getDateCreated().hour << ":" <<
			star_lists->current()->getDateCreated().minute << "~" << star_lists->current()->getDateCreated().day << "/" <<
			star_lists->current()->getDateCreated().month << "/" << star_lists->current()->getDateCreated().year << "~|";
		star_lists->next();
	}
	star_lists->goToStart();
	outfile.close();
	std::cout << "Saved!\n";
}

void view(StarListIterator* star_lists)
{
	std::string extra;
	std::string star_title;
	std::cout << "Care to mention the title of the star you're looking for?\n";
	std::getline(std::cin, extra);
	std::getline(std::cin, star_title);
	std::cout << star_title;
	
	while(star_lists->hasNext())
	{
		if (star_lists->current()->getStarTitle() == star_title)
		{
			std::cout << "Found it!\n";
			std::cout << "Here's your note\n";
			std::cout << "Title: " << star_lists->current()->getStarTitle() << "\n";
			std::cout << "Created on: " << star_lists->current()->getDateCreated().day << "/" <<
				star_lists->current()->getDateCreated().month << "/" << star_lists->current()->getDateCreated().year << "\n";
			for (unsigned int j = 0; j < star_lists->current()->getStarContent().size(); j++)
			{
				if (star_lists->current()->getStarContent().at(j).getIsItemChecked())
				{
					std::cout << "\t[X] " << star_lists->current()->getStarContent().at(j).getItemName() << "\n";
				}
				else
				{
					std::cout << "\t[] " << star_lists->current()->getStarContent().at(j).getItemName() << "\n";
				}
			}
			return;
		}
		star_lists->next();
	}
	star_lists->goToStart();
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
			StarList* star_list = add(star_lists);
			if (star_list)
			{
				star_lists->stars.push_back(star_list);
				std::cout << "Saved!\n";
			}
			else
			{
				std::cout << "Couldn't save.\n";
				std::cout << "Maybe try again\n";
			}
		}
		else if (command == "CHECK")
		{
			star_lists = check(star_lists);
		}
		else if (command == "EXIT")
		{
			return;
		}
		else if (command == "HELP")
		{
			help();
		}
		else if (command == "ORDER")
		{
			show(order(star_lists));
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
