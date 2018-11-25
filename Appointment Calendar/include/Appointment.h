#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "Time.h"

class Appointment
{
    public:
        Appointment(int=1,int=0,string="AM",int=1,int=0,string="AM");
        Appointment(const Time&,const Time&);
        virtual ~Appointment();

        void set_start(const Time&);
        void set_end(const Time&);

        Time get_start()const;
        Time get_end()const;

        bool operator< (const Appointment&);
        bool operator> (const Appointment&);
        bool operator==(const Appointment&);
        bool operator!=(const Appointment&);
        bool operator<=(const Appointment&);
        bool operator>=(const Appointment&);
        Appointment operator= (const Appointment&);

        int value_format_end()const;
        friend istream& operator >>(istream&,Appointment&);
    protected:

    private:
        Time start,end;
};

#endif // APPOINTMENT_H
