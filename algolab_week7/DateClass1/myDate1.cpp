#include <iostream>
#include "myDate.h"

myDate::myDate(int year, int month, int day){
    this->year = year;
    this->month = month;
    this->day = day;
}

int myDate::getDayOfMonth() const{
    return day;
}

int myDate::getMonth() const{
    return month;
}

int myDate::getYear() const{
    return year;
}

void myDate::setDayOfMonth(int day){
    this->day = day;
}

void myDate::setMonth(int month){
    this->month = month;
}

void myDate::setYear(int year){
    this->year = year;
}

void myDate::setDate(int year, int month, int day){
    this->year = year;
    this->month = month;
    this->day = day;
}

bool myDate::isLeapYear() const{
    if( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) )
        return 1;
    return 0;
}

int myDate::getDayOfWeek() const{
    int result = 0;
    int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int j = 1; j < year; j++){
        if( ((j % 4 == 0) && (j % 100 != 0)) || (j % 400 == 0) )
            result += 366;
        else
            result += 365;
    }

    for(int j = 0; j < month-1; j++){
        if(j == 1){
            if(isLeapYear())
                result += (end_of_month[j] + 1);
            else
                result += end_of_month[j];
        }
        else{
            result += end_of_month[j];
        }
    }
    result += day;
    return result % 7;
}
