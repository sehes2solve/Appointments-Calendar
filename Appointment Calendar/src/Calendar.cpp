#include "Calendar.h"

Calendar::Calendar():numOfDays(7)
{
    days = new DayAppointments[7];
    for(int i = 0;i < 7;i++)
    {
        (*(days + i)).set_weekDay(days[i].week[i]);
    }
}
void Calendar :: insert_ap(istream& in,int num_days)
{
    num_days = (num_days < 1)? 1 : num_days;
    num_days = (num_days > 7)? 7 : num_days;
    string DayName;
    int order[7];
    for(int i = 0; i < num_days;i++)
    {
        in >> DayName;
        order[i] = DayAppointments :: day_ind(DayName);
        order[i] = (order[i] == -1)? 0 : order[i];
        (*(days + order[i])).set_numOfAppointments((*(days + order[i])).get_numOfAppointments() + 1);
    }
    (*(days + order[0])).insert_app(in,(*(days + order[0])).get_numOfAppointments()-1);
    Appointment* app = nullptr;
    Appointment* base_app = nullptr;
    base_app = (*(days + order[0])).get_appointments();
    for(int i = 1;i < num_days ;i++)
    {
         app = (*(days + order[i])).get_appointments();
         if(!(*(days + order[i])).Is_Overlapping_DayAppointmens(base_app[(*(days + order[0])).get_numOfAppointments()-1]))
            app[(*(days + order[i])).get_numOfAppointments()-1] = base_app[(*(days + order[0])).get_numOfAppointments()-1];
    }
}

void Calendar :: display_day(ostream& out, string dayname)
{
    int DayOrder = DayAppointments :: day_ind(dayname);
    DayOrder = (DayOrder == -1)? 0 : DayOrder;
    out << days[DayOrder];
}
void Calendar :: display_week(ostream& out)
{
    for(int i = 0;i < 7;i++)
        out << days[i];
}
void Calendar :: delete_ap(string dayname,int order)
{
    int DayOrder = DayAppointments :: day_ind(dayname);
    DayOrder = (DayOrder == -1)? 0 : DayOrder;
    (*(days + DayOrder)).delete_appointment(order);
}
void Calendar :: equaliz_days(string d1,string d2)
{
    int DayOrder1 = DayAppointments :: day_ind(d1);
    DayOrder1 = (DayOrder1 == -1)? 0 : DayOrder1;
    int DayOrder2 = DayAppointments :: day_ind(d2);
    DayOrder2 = (DayOrder2 == -1)? 0 : DayOrder2;
    string old_weekday = (*(days + DayOrder1)).get_weekDay();
    days[DayOrder1] = days[DayOrder2];
    (*(days + DayOrder1)).set_weekDay(old_weekday);
}
bool Calendar :: Is_common_app(string d1,string d2)
{
    int DayOrder1 = DayAppointments :: day_ind(d1);
    DayOrder1 = (DayOrder1 == -1)? 0 : DayOrder1;
    int DayOrder2 = DayAppointments :: day_ind(d2);
    DayOrder2 = (DayOrder2 == -1)? 0 : DayOrder2;
    return DayAppointments ::Is_having_equal_app(days[DayOrder1],days[DayOrder2]);
}
Calendar::~Calendar()
{
    delete [] days;
}
