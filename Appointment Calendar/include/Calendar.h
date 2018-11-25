#ifndef CALENDAR_H
#define CALENDAR_H
#include "DayAppointments.h"


class Calendar
{
    public:
        Calendar();
        virtual ~Calendar();
        void insert_ap(istream&,int);
        void display_day(ostream&,string);
        void display_week(ostream&);
        void delete_ap(string,int);
        void equaliz_days(string,string);
        bool Is_common_app(string,string);
    protected:
    private:
        DayAppointments* days;
        const int numOfDays;
};

#endif // CALENDAR_H
