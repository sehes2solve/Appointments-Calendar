#include "Time.h"

Time::Time(int hr ,int mn ,string dn)
{
    set_hour(hr);
    set_minute(mn);
    set_daynight(dn);
}

Time::~Time()
{
    //dtor
}


void Time ::  set_hour(int hr)
{
    if(hr > 12)
    {
        hour = hr % 13;
        if(hour % 2 == 1)
            set_dayhalf(!get_dayhalf());

    }
    else
        hour = (hr > 0) ? hr : 1 ;
}
void Time :: set_minute(int mn)
{
    if(mn > 59)
    {
        minute = mn % 60;
        set_hour(get_hour() + mn/60);
    }
    else
        minute = (mn >= 0) ? mn : 0 ;
}
void Time :: set_dayhalf(bool dh)
{
    dayhalf = (dh == 0 || dh == 1)? dh : 0;
    if(daynight == "PM")
                dayhalf = true;
            else
                dayhalf = false;
}
void Time :: set_daynight(string& dn)
{
    if(dn.length() == 2)
    {
//        transform(dn.begin(),dn.end(),dn.begin());
        dn = ToUpper(dn);
        if((dn[0] == 'A' || dn[0] == 'P') && dn[1] == 'M')
        {
            daynight = dn;
            if(daynight == "PM")
                dayhalf = true;
            else
                dayhalf = false;
        }
        else
        {
            daynight = "AM";
            dayhalf = false;
        }
    }
    else
        {
            daynight = "AM";
            dayhalf = false;
        }
}



int Time :: get_hour()const{ return hour; }
int Time :: get_minute()const{ return minute;}
string Time :: get_daynight() const{ return daynight; }
bool Time :: get_dayhalf()const{ return dayhalf; }

string Time :: ToUpper(string str)
{
    for(int i = 0 ; (unsigned)i < str.length();i++)
            str[i] = toupper(str[i]);
    return str;
}
int Time :: value_format()const
{
    return (dayhalf)? 12 + hour + minute : hour + minute;
}
bool Time :: operator< (const Time& t)const
{
    return (value_format() < t.value_format());
    /*if((dayhalf == false && t.dayhalf == true)||(dayhalf == t.dayhalf && hour < t.hour) || (dayhalf == t.dayhalf && hour == t.hour && minute < t.minute))
        return true;
    else
        return false;*/
}
bool Time :: operator> (const Time& t)const
{
    return (value_format() > t.value_format());
}
bool Time :: operator==(const Time& t)const
{
    return (value_format() == t.value_format());
    /*if(hour == t.hour && minute == t.minute && dayhalf == t.dayhalf)
        return true;
    else
        return false ;*/
}
bool Time :: operator!=(const Time& t)const
{
    return !(operator==(t));
}



