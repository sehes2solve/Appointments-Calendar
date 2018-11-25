#ifndef TIME_H
#define TIME_H
#include<string>

using namespace std;

class Time
{
    public:
        Time(int=1,int=0,string="AM");
        virtual ~Time();

        void set_hour(int);
        void set_minute(int);
        void set_daynight(string&);

        int get_hour() const;
        int get_minute() const;
        string get_daynight() const;
        bool get_dayhalf() const;


        bool operator< (const Time&)const;
        bool operator> (const Time&)const;
        bool operator==(const Time&)const;
        bool operator!=(const Time&)const;

        int value_format()const;
        static string ToUpper(string str);
    protected:

    private:
        void set_dayhalf(bool);
        int hour,minute;
        string daynight;
        bool dayhalf;/// false => am , true => pm ///
};

#endif // TIME_H
