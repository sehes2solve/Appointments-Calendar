#ifndef DAYAPPOINTMENTS_H
#define DAYAPPOINTMENTS_H
#include "Appointment.h"

class DayAppointments
{
    public:
        DayAppointments(string=week[0],int=1);
        DayAppointments(const DayAppointments&);
        virtual ~DayAppointments();

        //void set_appointments(Appointment*);
        void set_numOfAppointments(int);
        void set_weekDay(string);

        Appointment* get_appointments()const;
        int get_numOfAppointments()const;
        string get_weekDay()const;

        DayAppointments operator= (const DayAppointments&);
        bool operator==(const DayAppointments&)const;
        bool operator!=(const DayAppointments&)const;
        Appointment operator[] (int i)const;

        static int day_ind(string day);
        void insert_app(istream&,int);
        bool Is_Overlapping_DayAppointmens(const Appointment&)const;
        static bool Is_having_equal_app(const DayAppointments&,const DayAppointments&);
        void delete_appointment(int);
        friend istream& operator >>(istream&, DayAppointments&);
        friend ostream& operator <<(ostream&, const DayAppointments&);

        static string week[7] ;
    protected:

    private:
        bool Is_Overlapping(const Appointment&,const Appointment&)const;
        Appointment* appointments;
        int numOfAppointments;
        string weekDay;

};

#endif // DAYAPPOINTMENTS_H
