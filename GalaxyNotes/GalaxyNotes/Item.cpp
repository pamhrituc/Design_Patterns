#include "Item.h"



Item::Item()
{
}

std::string Item::getItemName() const
{
	return this->item_name;
}

bool Item::getIsItemChecked() const
{
	return this->is_item_checked;
}

void Item::setItemName(std::string name)
{
	this->item_name = name;
}

void Item::setIsItemChecked(bool item_checked)
{
	this->is_item_checked = item_checked;
}


Item::~Item()
{
}
