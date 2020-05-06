#include "Item.h"



Item::Item()
{
}

std::string Item::getItemName()
{
	return this->item_name;
}

bool Item::getIsItemChecked()
{
	return this->is_item_checked;
}

void Item::setIsItemChecked(bool item_checked)
{
	this->is_item_checked = item_checked;
}


Item::~Item()
{
}
