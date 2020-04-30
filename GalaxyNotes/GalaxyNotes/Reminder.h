#pragma once
#include "Star.h"

class Reminder : public Star
{
private:
	DateTime date_created;
	DateTime date_modified;
	std::string reminder_title;
	DateTime reminder_date;
public:
	Reminder();
	void createStar(std::string reminder_title) override;
	DateTime getDateCreated() const override;
	DateTime getDateModified() const override;
	std::string getStarTitle() const override;
	DateTime getReminderDate() const;
	~Reminder();
};

