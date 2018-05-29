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

int myDate::getDayOfYear() const{
    int result = 0;
    int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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
    return result;
}

int myDate::getDayOfYear(int mymonth, int myday) const{
    int result = 0;
    int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int j = 0; j < mymonth-1; j++){
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
    result += myday;
    return result;
}

int myDate::getNumHolidays() const{
    int holiday = 0;
    int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int result = 0;

    myDate m(year, 1, 1);
    int temp = m.getDayOfWeek() - 1;

    if(isLeapYear()){
        end_of_month[1] = 29;
    }

    for(int m = 1; m <= 12; m++){
        for(int d = 1; d <= end_of_month[m-1]; d++){
            temp++;
            if(temp % 7 == 0 || temp % 7 == 6){
                holiday++;
            }

            if(m == 1 && d == 1){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 3 && d == 1){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 2 && d == 1){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 2 && d == 2){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 2 && d == 3){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 5 && d == 5){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 6 && d == 6){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 7 && d == 17){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 8 && d == 15){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 9 && d == 15){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 9 && d == 16){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 9 && d == 17){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 10 && d == 3){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 12 && d == 25){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }
            else if(m == 5 && d == 15){
                if(temp % 7 != 0 && temp % 7 != 6){
                    holiday++;
                }
            }

        }
    }


    return holiday;
}
