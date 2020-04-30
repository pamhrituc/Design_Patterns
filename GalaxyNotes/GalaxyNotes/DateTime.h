#pragma once
class DateTime
{
public:
	int minute;
	int hour;
	int day;
	int month;
	int year;
	DateTime();
	DateTime(int hour, int minute, int day, int month, int year) : hour(hour), minute(minute), day(day), month(month), year(year) {}
	~DateTime();
};

