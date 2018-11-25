#include "DayAppointments.h"

string DayAppointments :: week[7] = {"SATURDAY","SUNDAY","MONDAY","TUESDAY","WEDNSDAY","THURSDAY","FRIDAY"};

DayAppointments::DayAppointments(string day,int num):appointments(nullptr)
{
    set_numOfAppointments(num);
    set_weekDay(day);
}
DayAppointments::DayAppointments(const DayAppointments& cpy):appointments(nullptr)
{
    set_numOfAppointments(cpy.numOfAppointments);
    set_weekDay(cpy.weekDay);
    for(int i = 0;i < numOfAppointments;i++)
        appointments[i] = cpy.appointments[i];
}
DayAppointments DayAppointments::operator=(const DayAppointments& cpy)
{
    set_numOfAppointments(cpy.numOfAppointments);
    set_weekDay(cpy.get_weekDay());
    for(int i = 0;i < numOfAppointments;i++)
    {
        if(!(Is_Overlapping_DayAppointmens(cpy.appointments[i])))
            appointments[i] = cpy.appointments[i];
    }
    return *this;
}
bool DayAppointments :: operator==(const DayAppointments& DayApp)const
{
    for(int i = 0;i < numOfAppointments;i++)
    {
        if(appointments[i] == DayApp.appointments[i])
            continue;
        else
            return false;
    }
    return true;
}
bool DayAppointments :: operator!=(const DayAppointments& DayApp)const
{
    return !(DayAppointments :: operator==(DayApp));
}
Appointment DayAppointments :: operator[] (int i)const
{
    if(i < 0)
        return appointments[0];
    else if(i >= numOfAppointments)
        return appointments[numOfAppointments-1];
    else
        return appointments[i];
}
DayAppointments::~DayAppointments()
{
    delete[] appointments;
}

void DayAppointments :: set_numOfAppointments(int num)
{
    if(appointments != nullptr)
    {
        Appointment* temp = new Appointment[numOfAppointments];
        for(int i = 0; i < numOfAppointments; i++)
            temp[i] = appointments[i];
        delete[] appointments;
        appointments = nullptr;
        int smaller_ln = (num < numOfAppointments) ? num : numOfAppointments;
        numOfAppointments = (num > 0) ? num : 1;
        appointments = new Appointment[numOfAppointments];
        for(int i = 0; i < smaller_ln; i++)
            appointments[i] = temp[i];
        delete[] temp;
    }
    else
    {
        numOfAppointments = (num > 0) ? num : 1;
        appointments = new Appointment[numOfAppointments];
    }

}
void DayAppointments :: set_weekDay(string day)
{
    int dayOrder = day_ind(day);
    weekDay = week[(dayOrder != -1)? dayOrder : 0];
}

Appointment* DayAppointments :: get_appointments()const{ return appointments; }
int DayAppointments :: get_numOfAppointments()const{ return numOfAppointments; }
string DayAppointments :: get_weekDay()const{ return weekDay;}

bool DayAppointments :: Is_Overlapping_DayAppointmens(const Appointment& app)const
{
    for(int i = 0;i < numOfAppointments;i++)
    {
        if(Is_Overlapping(appointments[i],app))
            return true;
    }
    return false;
}
bool DayAppointments :: Is_Overlapping(const Appointment& app1,const Appointment& app2)const
{
    if((app1.get_start() > app2.get_start()) && (app1.get_start().value_format() < app2.value_format_end()))
        return true;
    else if((app2.get_start() > app1.get_start()) && (app2.get_start().value_format() < app1.value_format_end()))
        return true;
    else if(app1.get_start() == app2.get_start())
        return true;
    else if(app1.get_start() == app2.get_end())
        return true;
    else if(app1.get_end() == app2.get_start())
        return true;
    else if(app1.get_end() == app2.get_end())
        return true;
    else return false;
}
int DayAppointments :: day_ind(string day)
{
    day = Time :: ToUpper(day);
    for(int i = 0;i < 7;i++)
    {
        if(day == week[i])
            return i;
    }
    return -1;
}

void DayAppointments :: insert_app(istream& in,int order)
{
    order = (order < 0)? 0 : order;
    order = (order > numOfAppointments - 1)? numOfAppointments - 1 : order;
    Appointment temp;
    in >> temp;
    if(!Is_Overlapping_DayAppointmens(temp))
              appointments[order] = temp;
}
void DayAppointments :: delete_appointment(int ind)
{
    ind = (ind < 0)? 0 : ind ;
    ind = (ind > get_numOfAppointments() - 1)? get_numOfAppointments() - 1 : ind ;
    for(int i = ind + 1;i < numOfAppointments;i++)
        appointments[i-1] = appointments[i];
    set_numOfAppointments(numOfAppointments-1);
}
bool DayAppointments :: Is_having_equal_app(const DayAppointments& day1,const DayAppointments& day2)
{
    if(day1.numOfAppointments < day2.numOfAppointments)
    {
        for(int i = 0;i <day2.numOfAppointments;i++)
        {
            if(day1.Is_Overlapping_DayAppointmens(day2[i]))
                return true;
        }
        return false;
    }
    else
    {
        for(int i = 0;i <day1.numOfAppointments;i++)
        {
            if(day2.Is_Overlapping_DayAppointmens(day1[i]))
                return true;
        }
        return false;
    }
}
