#include "Appointment.h"

Appointment::Appointment(int st_hr ,int st_mn ,string st_dn,int en_hr ,int en_mn ,string en_dn)
{
    start.set_hour(st_hr);
    start.set_minute(st_mn);
    start.set_daynight(st_dn);
    end.set_hour(en_hr);
    end.set_minute(en_mn);
    end.set_daynight(en_dn);
}
Appointment::Appointment(const Time& st,const Time& en)
{
    set_start(st);
    set_end(en);
}
Appointment::~Appointment()
{
    //dtor
}

void Appointment :: set_start(const Time& st){ start = st;}
void Appointment :: set_end(const Time& en){ end = en;}

Time Appointment :: get_start()const{ return start;}
Time Appointment :: get_end()const{ return end;}

bool Appointment :: operator< (const Appointment& app)
{
    return value_format_end() - start.value_format() < app.value_format_end() - app.start.value_format() ;
}
bool Appointment :: operator> (const Appointment& app)
{
    return value_format_end() - start.value_format() > app.value_format_end() - app.start.value_format() ;
}
bool Appointment :: operator==(const Appointment& app)
{
    return start == app.start && end == app.end;
}
bool Appointment :: operator!=(const Appointment& app)
{
    return !(operator==(app));
}
bool Appointment :: operator<=(const Appointment& app)
{
    return *this < app || *this == app;
}
bool Appointment :: operator>=(const Appointment& app)
{
    return *this > app || *this == app;
}
Appointment Appointment :: operator= (const Appointment& app)
{
    start = app.start;
    end = app.end;
    return (*this);
}
int Appointment :: value_format_end()const
{
    return (start > end)? 24 + end.value_format(): end.value_format();
}

