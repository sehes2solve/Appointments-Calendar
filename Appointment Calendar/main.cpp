#include <iostream>
#include <stdlib.h>
#include "Calendar.h"
#include <cstring>

using namespace std;

void display();
istream& operator >>(istream&, Time&);
ostream& operator <<(ostream&,const Time&);
istream& operator >>(istream&, Appointment&);
ostream& operator <<(ostream&,const Appointment&);
istream& operator >>(istream&, DayAppointments&);
ostream& operator <<(ostream&,const DayAppointments&);

int main()
{
    /*Time t1;
    Time t2;
    cin >> t1;
    cin >> t2;
    t1 = t2;
    cout << t1 << t2;
    cout << (t1==t2) << (t1!=t2) << (t1>t2)<< (t1<t2) ;*/

    /*Appointment app1;
    Appointment app2;
    cout << app1 << app2;
    cin >> app1 >> app2 ;
    cout << app1 << app2;
    cout << (app1==app2) << (app1!=app2) << (app1>app2)<< (app1<app2) << (app1 >= app2) << (app1 <=app2);*/

   /* DayAppointments d("lolo",5);
    cin >> d;
    DayAppointments d2(d);
    cout << d2;



    cout << d[3];
    //Calendar y;*/
    bool Is_exit = false;
    Calendar cal;
    while(!Is_exit)
    {
        display();
        char choice;
        cin >> choice;
        if(choice == '1')
        {
            cout << "Enter number of days the appointment will be inserted into : ";
            string num_days;
            cin >> num_days;
            cout << "Enter name of days/number of appointments/hr-min-daynight of each appointment\nRespectively : \n";
            int no;
            if(num_days.length() == 1)
                no = num_days[0] - '0';
            else
                no = 1;
            cal.insert_ap(cin,no);
        }
        else if(choice == '2')
        {
            string day;
            cout << "Enter name of day to display : ";
            cin >> day;
            cal.display_day(cout,day);
        }
        else if(choice == '3')
        {
            cal.display_week(cout);
        }
        else if(choice == '4')
        {
            string day,order;
            cout << "Enter name of day that will delete from : ";
            cin >> day;
            cout << "Enter order of appointment to delete : ";
            cin >> order;
            char* order_of_app = new char[order.length()];
            strcpy(order_of_app,order.c_str());
            cal.delete_ap(day,atoi(order_of_app));
            delete[] order_of_app;
        }
        else if(choice == '5')
        {
            string day1,day2;
            cout << "Enter name of day that will change it's value : ";
            cin >> day1;
            cout << "Enter name of day that will copy from : ";
            cin >> day2;
            cal.equaliz_days(day1,day2);
        }
        else if(choice == '6')
        {
            string day1,day2;
            cout << "Enter name of first day : ";
            cin >> day1;
            cout << "Enter name of second day : ";
            cin >> day2;
            cout << cal.Is_common_app(day1,day2);
        }
        else if(choice == '7')
            Is_exit = true;
        else
            cout << "Invalid Choice !!!\n" << endl;
    }

    return 0;
}
istream& operator >>(istream& in,Time& t)
{
    int hr,mn;
    string str_hr,str_mn,dh;
    in >> str_hr >> str_mn >> dh;
    char* temp = new char[str_hr.length()];
    strcpy(temp,str_hr.c_str());
    hr = atoi(temp);
    delete [] temp;
    temp = new char[str_mn.length()];
    strcpy(temp,str_mn.c_str());
    mn = atoi(temp);
    delete[] temp;
    t.set_hour(hr);
    t.set_minute(mn);
    t.set_daynight(dh);
    return in ;
}

ostream& operator <<(ostream& out,const Time& t)
{
    if(t.get_hour() < 10)
        out << 0;
    out << t.get_hour() << ':' ;
    if(t.get_minute() < 10)
        out << 0;
    out << t.get_minute() << ' '
        << t.get_daynight()<< ' '
        << t.get_dayhalf()<< '\n';
    /* << ((t.get_hour() < 10) ? ( 0 << t.get_hour()) : t.get_hour()) << ':'
        << ((t.get_minute() < 10) ? (0 << t.get_minute()) : t.get_minute()) <<' ';
        << t.get_dayhalf() << '\n' ;*/
    return out ;
}

istream& operator >>(istream&in , Appointment& app)
{
    in >> app.start >> app.end ;
    return in;
}
ostream& operator <<(ostream& out,const Appointment& app)
{
    out << "Start Time : " << app.get_start() << "\nEnd Time : " << app.get_end() << '\n';
    return out;
}
istream& operator >>(istream& in, DayAppointments& dyapp)
{
    int num;
    string weekday;
    in >> weekday >> num ;
    dyapp.set_numOfAppointments(num);
    dyapp.set_weekDay(weekday);
    Appointment temp;
    for(int i = 0;i < dyapp.get_numOfAppointments();i++)
        dyapp.insert_app(in,i);
    return in;
}
ostream& operator <<(ostream& out,const DayAppointments& dyapp)
{
    out << "Day : "<< dyapp.get_weekDay() << "\nNumber of Appointments : " << dyapp.get_numOfAppointments() << '\n'  ;
    for(int i = 0;i < dyapp.get_numOfAppointments();i++)
        out << "Appointment : (" << i + 1 << ")\n" << dyapp[i] << '\n';
        return out;
}
void display()
{
    cout << "*----------------Appointments Calendar----------------*\n"
         << "Please insert a choice : \n1-Insert an Appointment\n"
         << "2-Display Appointments for a day\n"
         << "3-Display Appointments for the week\n"
         << "4-Delete an Appointment\n"
         << "5-Make Appointments of a day equal to that of another day\n"
         << "6-Check if two days has equal appointments\n"
         << "7-Exit\n\n\n";
}
