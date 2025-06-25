#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
using namespace std;


//Class which can set the time in hours and minutes and can output the same
class Time
{
private:
    int minutes;
    int hour;

public:
    Time(int hour = 0, int minutes = 0) : minutes(minutes), hour(hour) {}

    void setMinutes(const int &minutes) { this->minutes = minutes; }
    void setHour(const int &hours) { this->hour = hours; }

    int getMinutes() const { return minutes; }
    int getHour() const { return hour; }
};


//Class which can set the date and output the same in days months and years
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day = 0, int month = 0, int year = 0) : day(day), month(month), year(year) {}

    void setYear(const int &year) { this->year = year; }
    void setMonth(const int &month) { this->month = month; }
    void setDay(const int &day) { this->day = day; }

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
};

#endif