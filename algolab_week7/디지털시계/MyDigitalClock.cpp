#include <iomanip>
#include <string>
#include "MyDigitalClock.h"
// constructors
MyDigitalClock::MyDigitalClock (int h, int m, bool ap)
:hour(h), min(m), am_pm(ap)
{
}
MyDigitalClock::MyDigitalClock (char clock[])
{
    string temp = clock;
    if(temp[0] == '0'){ hour = temp[1] - '0'; }
    else if(temp[0] != '0') { hour = (temp[0] - '0') * 10 + (temp[1] - '0'); }

    if(temp[3] == '0'){ min = temp[4] - '0'; }
    else if(temp[3] != '0') { min = (temp[3] - '0') * 10 + (temp[4] - '0'); }

    if(temp[5] == 'A') { am_pm = false; }
    else { am_pm = true; }
}
MyDigitalClock MyDigitalClock::tick()
{
 ++min;
 if(min == 60)
 {
 hour++;
 min = 0;
 }
 if(hour == 13)
 hour = 1;
 if(hour == 12 && min == 0)
 am_pm = !am_pm;
 return *this;
}
MyDigitalClock MyDigitalClock::untick()
{
    --min;
    if(min == -1){
        hour--;
        min = 59;
    }
    if(hour == 0){
        hour = 12;
    }
    if(hour == 11 && min == 59){
        am_pm = !am_pm;
    }
 return *this;
}
MyDigitalClock MyDigitalClock::operator ++()
{
 return tick();
}
MyDigitalClock MyDigitalClock::operator ++(int)
{
 MyDigitalClock c = *this;
 tick();
 return c;
}
MyDigitalClock MyDigitalClock::operator --()
{
 return untick();
}
MyDigitalClock MyDigitalClock::operator --(int)
{
 MyDigitalClock c = *this;
 untick();
 return c;
}
ostream& operator<<(ostream& oStream, const MyDigitalClock& c)
{
 oStream << setfill('0') << setw(2) << c.hour << ':' << setw(2) << c.min;
 if(!c.am_pm)
 oStream << "AM";
 else
 oStream << "PM";
 oStream << endl;
 return oStream;
}
