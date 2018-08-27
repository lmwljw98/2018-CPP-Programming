#ifndef _MYDATE_H_
#define _MYDATE_H_
#include <iostream>
using namespace std;
class myDate {
public:
     // Constructor (생성자)
     myDate(int year=1582, int month=1, int day=1);
     // Accessor functions (접근자)
     int getDayOfMonth() const;
     int getMonth() const;
     int getYear() const;
     // Mutator functions (변경자)
     void setDayOfMonth(int day);
     void setMonth(int month);
     void setYear(int year);
     void setDate(int year, int month, int day);
     // utility functions
     bool isLeapYear() const; //윤년
     int getDayOfWeek() const; //0=Sunday, 1=Monday, ..., 6=Saturday
     int getDayOfYear() const; //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
     int getNumHolidays() const; //휴일수 계산
     int getNumSummerTimeDays()const; //써머타임 날짜수
     void printCalendarOfMonth() const; // 달력출력하기
private:
    // information hiding : implement as you wish
    int year;
    int month;
    int day;
};
#endif
