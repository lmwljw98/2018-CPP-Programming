#include <iostream>
#include "myDate.h"
#include <cstdlib>

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

bool myDate::isLeapYear(int year) const{
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

int myDate::getTotalDay() const{
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
    return result;
}

int myDate::getDayOfWeek(int year, int month, int day) const{
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

int myDate::getDayOfYear(int year, int month, int day) const{
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

int myDate::getNumSummerTimeDays() const{
    int d3 = 31;
    int d10 = 31;
    while(getDayOfWeek(year, 3, d3) != 0){
        d3--;
    }
    while(getDayOfWeek(year, 10, d10) != 0){
        d10--;
    }

    int march = getDayOfYear(year, 3, d3);
    int october = getDayOfYear(year, 10, d10);

    return october - march;
}

void myDate::printCalendarOfMonth() const{
    int day = 1;
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
            if( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) )
                result += (end_of_month[j] + 1);
            else
                result += end_of_month[j];
        }
        else{
            result += end_of_month[j];
        }
    }
    result += day;

    int first_of_month = result % 7;
    int index = 0;
    cout << year << " " << month << endl;
    for(int j = 0; j < first_of_month; j++){
        cout << 0 << " ";
        index++;
    }
    for(int j = 1; j <= end_of_month[month-1]; j++){
        cout << j << " ";
        index++;
        if(index == 7){
            cout << endl;
            index = 0;
        }
    }
    if(month == 2){
        if( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ){
            cout << 29 << " ";
            index++;
            if(index == 7){
                cout << endl;
                index = 0;
            }
        }
    }

    for(int j = index; j < 7; j++){
        if(index == 0)
            break;
        cout << 0 << " ";
    }
    if(index != 0)
        cout << endl;
}

ostream &operator <<(ostream &outStream, const myDate& date){
    if(date.getDayOfMonth() < 10)
        outStream << "0" << date.getDayOfMonth();
    else
        outStream << date.getDayOfMonth();

    if(date.getMonth() < 10)
        outStream << "/0" << date.getMonth();
    else
        outStream << "/" << date.getMonth();

    outStream << "/" << date.getYear();
    return outStream;
}

istream &operator >>(istream &inStream, myDate& date){
    int y, m, d;
    inStream >> y >> m >> d;
    date.setDate(y, m, d);
    return inStream;
}

myDate operator +(int num, const myDate& date) {
    int year = date.getYear();
    int month = date.getMonth();
    int day = date.getDayOfMonth();
    int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < abs(num); i++) {
        if(date.isLeapYear(year)) { end_of_month[1] = 29; }
        else { end_of_month[1] = 28; }

        if (num > 0) {
            day++;
            if (day > end_of_month[month - 1]) {
                month++; day = 1;
            }
            if (month > 12) {
                year++; month = 1;
            }
        }
        else {
            day--;
            if (day < 1) {
                month--;
                day = end_of_month[month - 1];
            }
            if (month < 1) {
                year--; month = 12; day = 31;
            }
            if (year < 1582) {
                year = 1582; month = 1; day = 1;
            }
        }
    }
    myDate result = myDate(year, month, day);

    return result;
}

int myDate::operator -(const myDate& date) const{
    int a = getTotalDay();
    int b = date.getTotalDay();
    return a - b;
}

myDate myDate::operator +(int num) const {
    int year = getYear();
    int month = getMonth();
    int day = getDayOfMonth();
    int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < abs(num); i++) {
        if(isLeapYear(year)) { end_of_month[1] = 29; }
        else { end_of_month[1] = 28; }

        if (num > 0) {
            day++;
            if (day > end_of_month[month - 1]) {
                month++; day = 1;
            }
            if (month > 12) {
                year++; month = 1;
            }
        }
        else {
            day--;
            if (day < 1) {
                month--;
                day = end_of_month[month - 1];
            }
            if (month < 1) {
                year--; month = 12; day = 31;
            }
            if (year < 1582) {
                year = 1582; month = 1; day = 1;
            }
        }
    }
    myDate result = myDate(year, month, day);

    return result;
}

myDate myDate::operator -(int num) const {
    int year = getYear();
    int month = getMonth();
    int day = getDayOfMonth();
    int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < abs(num); i++) {
        if(isLeapYear(year)) { end_of_month[1] = 29; }
        else { end_of_month[1] = 28; }

        if (num < 0) {
            day++;
            if (day > end_of_month[month - 1]) {
                month++; day = 1;
            }
            if (month > 12) {
                year++; month = 1;
            }
        }
        else {
            day--;
            if (day < 1) {
                month--;
                day = end_of_month[month - 1];
            }
            if (month < 1) {
                year--; month = 12; day = 31;
            }
            if (year < 1582) {
                year = 1582; month = 1; day = 1;
            }
        }
    }
    myDate result = myDate(year, month, day);

    return result;
}

myDate& myDate::operator ++() {
    int year = getYear();
    int month = getMonth();
    int day = getDayOfMonth();
    int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(isLeapYear()) { end_of_month[1] = 29; }
    else { end_of_month[1] = 28; }

    day++;
    if (day > end_of_month[month - 1]) {
        month++; day = 1;
    }
    if (month > 12) {
        year++; month = 1;
    }
    setDate(year, month, day);

    return *this;
}

myDate& myDate::operator --() {
    int year = getYear();
    int month = getMonth();
    int day = getDayOfMonth();
    int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(isLeapYear()) { end_of_month[1] = 29; }
    else { end_of_month[1] = 28; }

    day--;
    if (day < 1) {
        month--; day = end_of_month[month - 1];
    }
    if (month < 1) {
        year--; month = 12; day = 31;
    }
    if (year < 1582) {
        year = 1582; month = 1; day = 1;
    }
    setDate(year, month, day);

    return *this;
}

myDate myDate::operator ++(int) {
    myDate temp = *this;
    int year = getYear();
    int month = getMonth();
    int day = getDayOfMonth();
    int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(isLeapYear()) { end_of_month[1] = 29; }
    else { end_of_month[1] = 28; }

    day++;
    if (day > end_of_month[month - 1]) {
        month++; day = 1;
    }
    if (month > 12) {
        year++; month = 1;
    }
    setDate(year, month, day);

    return temp;
}

myDate myDate::operator --(int) {
    myDate temp = *this;
    int year = getYear();
    int month = getMonth();
    int day = getDayOfMonth();
    int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(isLeapYear()) { end_of_month[1] = 29; }
    else { end_of_month[1] = 28; }

    day--;
    if (day < 1) {
        month--; day = end_of_month[month - 1];
    }
    if (month < 1) {
        year--; month = 12; day = 31;
    }
    if (year < 1582) {
        year = 1582; month = 1; day = 1;
    }
    setDate(year, month, day);

    return temp;
}

myDate& myDate::operator =(const myDate& date) {
    setDate(date.getYear(), date.getMonth(), date.getDayOfMonth());
    return *this;
}

myDate& myDate::operator +=(int num) {
    int year = getYear();
    int month = getMonth();
    int day = getDayOfMonth();
    int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < abs(num); i++) {
        if(isLeapYear(year)) { end_of_month[1] = 29; }
        else { end_of_month[1] = 28; }

        if (num > 0) {
            day++;
            if (day > end_of_month[month - 1]) {
                month++; day = 1;
            }
            if (month > 12) {
                year++; month = 1;
            }
        }
        else {
            day--;
            if (day < 1) {
                month--;
                day = end_of_month[month - 1];
            }
            if (month < 1) {
                year--; month = 12; day = 31;
            }
            if (year < 1582) {
                year = 1582; month = 1; day = 1;
            }
        }
    }
    setDate(year, month, day);

    return *this;
}

myDate& myDate::operator -=(int num) {
    int year = getYear();
    int month = getMonth();
    int day = getDayOfMonth();
    int end_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < abs(num); i++) {
        if(isLeapYear(year)) { end_of_month[1] = 29; }
        else { end_of_month[1] = 28; }

        if (num < 0) {
            day++;
            if (day > end_of_month[month - 1]) {
                month++; day = 1;
            }
            if (month > 12) {
                year++; month = 1;
            }
        }
        else {
            day--;
            if (day < 1) {
                month--;
                day = end_of_month[month - 1];
            }
            if (month < 1) {
                year--; month = 12; day = 31;
            }
            if (year < 1582) {
                year = 1582; month = 1; day = 1;
            }
        }
    }
    setDate(year, month, day);

    return *this;
}

bool myDate::operator >(const myDate& date) const{
    if (getYear() > date.getYear())
        return true;
    else if (getYear() == date.getYear() && getMonth() > date.getMonth())
        return true;
    else if (getYear() == date.getYear() && getMonth() == date.getMonth() && getDayOfMonth() > date.getDayOfMonth())
        return true;
    else
        return false;
}

bool myDate::operator >=(const myDate& date) const {
    if (getYear() > date.getYear())
        return true;
    else if (getYear() == date.getYear() && getMonth() > date.getMonth())
        return true;
    else if (getYear() == date.getYear() && getMonth() == date.getMonth() && getDayOfMonth() >= date.getDayOfMonth())
        return true;
    else
        return false;
}

bool myDate::operator <(const myDate& date) const {
    if (getYear() < date.getYear())
        return true;
    else if (getYear() == date.getYear() && getMonth() < date.getMonth())
        return true;
    else if (getYear() == date.getYear() && getMonth() == date.getMonth() && getDayOfMonth() < date.getDayOfMonth())
        return true;
    else
        return false;
}

bool myDate::operator <=(const myDate& date) const {
    if (getYear() < date.getYear())
        return true;
    else if (getYear() == date.getYear() && getMonth() < date.getMonth())
        return true;
    else if (getYear() == date.getYear() && getMonth() == date.getMonth() && getDayOfMonth() <= date.getDayOfMonth())
        return true;
    else
        return false;
}

bool myDate::operator ==(const myDate& date) const {
    if (getYear() == date.getYear() && getMonth() == date.getMonth() && getDayOfMonth() == date.getDayOfMonth())
        return true;
    else
        return false;
}

bool myDate::operator !=(const myDate& date) const {
    if (getYear() == date.getYear() && getMonth() == date.getMonth() && getDayOfMonth() == date.getDayOfMonth())
        return false;
    else
        return true;
}
