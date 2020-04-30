#pragma once
#include <string>
#include "DateTime.h"
#include "Star.h"

class Note : public Star {
private:
	DateTime date_created;
	DateTime date_modified;
	std::string note_title;
	std::string note_content;
public:
	Note();
	void createStar(std::string note_title) override;
	DateTime getDateCreated() const override;
	DateTime getDateModified() const override;
	std::string getStarTitle() const override;
	std::string getNoteContent() const;
	~Note();
};