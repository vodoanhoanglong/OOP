#include <iostream>
using namespace std;

class MyTime
{
    private:
        int seconds, minute, hours;
    public:
        MyTime();
        MyTime(int seconds, int month, int hours);
        MyTime(const int a);
        void Nhap();
        void Xuat();
        bool operator >=(MyTime MyTime);
        int get_hours();
        int get_minute();
        int get_seconds();
};
MyTime::MyTime()
{
    this->seconds = 25;
    this->minute = 8;
    this->hours = 2001;
}
MyTime::MyTime(int seconds, int minute, int hours)
{
    this->seconds = seconds;
    this->minute = minute;
    this->hours = hours;
}
MyTime::MyTime(const int a)
{
    this->seconds = this->minute = this->hours = a;
}
void MyTime::Nhap()
{
    cout<<"\nNhap gio: "; cin>>hours;
    cout<<"\nNhap phut: "; cin>>minute;
    cout<<"\nNhap giay: "; cin>>seconds;
}
void MyTime::Xuat()
{
    cout<<hours<<" : "<<minute<<" : "<<seconds<<endl;
}
bool MyTime::operator >=(MyTime MyTime)
{
    if (this->hours > MyTime.hours)
        return true;
    if (this->hours == MyTime.hours && this->minute > MyTime.minute) 
        return true;
    if (this->minute == MyTime.minute && this->seconds == MyTime.seconds && this->seconds >= MyTime.seconds) 
        return true;
    return false;
}

int MyTime::get_seconds()
{
    return this->seconds;
}
int MyTime::get_minute()
{
    return this->minute;
}
int MyTime::get_hours()
{
    return this->hours;
}
int main()
{
    MyTime a[5], MyTime1, MyTime2 , max, min;
    
    cout<<"Nhap MyTime 1: "; MyTime1.Nhap();
    cout<<"Nhap MyTime 2: "; MyTime2.Nhap();
    if( MyTime1 >= MyTime2)
       cout<<"MyTime 1 > MyTime 2"<<endl;
    else cout<<"MyTime 1 < MyTime 2"<<endl;

    for(int i = 0; i < 5; i++)
    {
        cout<<"Nhap vao thoi gian thu "<<i + 1<<": "<<endl;
        a[i].Nhap();
    }
    // Tìm thời gian lớn nhất
    max = a[0];
    for(int i =0; i < 5; i++)
        if (a[i] >= max) 
            max = a[i];
    cout<<"Thoi gian lon nhat: "; max.Xuat();


    system("pause");
    return 0;
}
