#pragma once
class DateTime
{
public:
	unsigned int minute;
	unsigned int hour;
	unsigned int day;
	unsigned int month;
	unsigned int year;
	DateTime();
	DateTime(unsigned int hour, unsigned int minute, unsigned int day, unsigned int month, unsigned int year) : hour(hour), minute(minute), day(day), month(month), year(year) {}
	~DateTime();
};