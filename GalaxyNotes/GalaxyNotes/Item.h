#pragma once
#include <string>

class Item
{
private:
	std::string item_name;
	bool is_item_checked;
public:
	Item();
	Item(std::string item_name) : item_name(item_name), is_item_checked(false) {}
	std::string getItemName() const;
	bool getIsItemChecked() const;
	void setItemName(std::string name);
	void setIsItemChecked(bool item_checked);
	~Item();
};

