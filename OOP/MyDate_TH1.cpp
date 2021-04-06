//Bài 1.3, 1.9
#include <iostream>
using namespace std;

class MyDate
{
    private:
        int day, month, year;
    public:
        MyDate();
        MyDate(int day, int month, int year);
        MyDate(const int a);
        void Input();
        void Output();
        friend bool operator>=(MyDate md1, MyDate md2);
        bool operator>(MyDate md);
};
MyDate::MyDate()
{
    day = 1;
    month = 1;
    year = 2001;
}
MyDate::MyDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
MyDate::MyDate(const int a)
{
    this->day = this->month = this->year = a;
}
void MyDate::Input()
{
    cout<<"Enter day: "<<endl; cin>>day;
    cout<<"Enter month: "<<endl; cin>> month;
    cout<<"Enter year: "<<endl; cin>>year;
}
void MyDate::Output()
{
    cout<<day<<"/"<<month<<"/"<<year<<endl;
}
bool operator>=(MyDate md1, MyDate md2)
{
    if(md1.year > md2.year)
        return true;
    else if(md1.year == md2.year)
    {
        if(md1.month > md2.month)
            return true;
        else if(md1.month == md2.month)
        {
            if(md1.day > md2.day)
                return true;
            return false;
        }
        return false;
    }
    return false;
}
bool MyDate::operator>(MyDate md)
{
    if(this->year > md.year)
        return true;
    else if(this->year == md.year)
    {
        if(this->month > md.month)
            return true;
        else if(this->month == md.month)
        {
            if(this->day > md.day)
                return true;
            return false;
        }
        return false;
    }
    return false;
}
int main()
{
    MyDate *a, b(22,9,2002), c(3,3,2001), d, *e;
    cout<<"So sanh >="<<endl;
    if(b>=c)
       cout<<"T >= L"<<endl;
    else cout<<"T <= L"<<endl;
    cout<<"So sanh >"<<endl;
    if(b>c)
       cout<<"T > L"<<endl;
    else cout<<"T < L"<<endl;
    int n = 5;
    a = new MyDate[n];
    cout<<"Enter 5 date: "<<endl; 
    for(int i=0; i<n; i++)
    {
        cout<<"Enter information date "<<i+1<<": "<<endl;
        a[i].Input();
    }
    d = a[0];
    for(int i=1; i<n; i++)
        if(a[i]>=d)
            d = a[i];
    cout<<"Date Max: "<<endl;
    d.Output();
    cout<<"Enter n date: ";
    cin>>n;
    e = new MyDate[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter information date "<<i+1<<": "<<endl;
        e[i].Input();
    }
    cout<<"Display n date: "<<endl;
    for(int i=0; i<n; i++)
        e[i].Output();
    cout<<"Sort up ascending: "<<endl;
    for(int i=0; i<n-1; i++)
        for(int j=1; j<n; j++)
            if(e[i] > e[j])
            {
                MyDate temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
    for(int i=0; i<n; i++)
        e[i].Output();
    system("pause");
}
