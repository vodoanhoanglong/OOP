#include <iostream>
using namespace std;

class MyDate
{
    private:
        int day, month, year;
    public:
        MyDate();
        MyDate(int day, int month, int year);
        ~MyDate();
        void input();
        void display();
        bool operator>(MyDate md);
};
MyDate::MyDate()
{
    this->day = 3;
    this->month = 3;
    this->year = 2001;
}
MyDate::MyDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
MyDate::~MyDate()
{

}
void MyDate::input()
{
    cout<<"Enter day: "; cin>>day;
    cout<<"Enter month: "; cin>>month;
    cout<<"Enter year: "; cin>>year;
    cout<<endl;
}
void MyDate::display()
{
    cout<<day<<"-"<<month<<"-"<<year<<endl;
}
bool MyDate::operator>(MyDate md)
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
class Person : public MyDate
{
    private: 
        string name, address;
        long int phone;
    public:
        Person();
        Person(string name, string address, long int phone);
        ~Person();
        void input();
        void display(); 
};
Person::Person()
{
    this->name = " ";
    this->address = " ";
    this->phone = NULL;

}
Person::Person(string name, string address, long int phone)
{
    this->name = name;
    this->address = address;
    this->phone = phone;
}
Person::~Person()
{

}
void Person::input()
{
    MyDate::input();
    cout<<"Enter name: "<<endl; 
    cin.ignore();
    getline(cin, name);
    cout<<"Enter address: "<<endl;
    getline(cin, address);
    cout<<"Enter phone: "<<endl;
    cin>>phone;
}
void Person::display()
{
    MyDate::display();
    cout<<"Name is: "<<name<<endl;
    cout<<"Address is: "<<address<<endl;
    cout<<"Phone is: "<<phone<<endl;
}
class Officer : public Person
{
    private:
        float salary;
    public:
        Officer();
        Officer(float salary);
        ~Officer();
        void input();
        void display();
};
Officer::Officer()
{
    this->salary = 0;
}
Officer::Officer(float salary)
{
    this->salary = salary;
}
Officer::~Officer()
{

}
void Officer::input()
{
    Person::input();
    cout<<"Enter salary: "<<endl; 
    cin>>salary;
}
void Officer::display()
{
    Person::display();
    cout<<"Salary is: "<<salary<<endl;
}
int main()
{
    Officer *a = new Officer[4];
    for(int i=0; i<4; i++)
    {
        cout<<"Enter obj "<<i+1<<": "<<endl;
        a[i].input();
    }
    cout<<"Sort: "<<endl;
    for(int i=0; i<4-1; i++)
        for(int j=1; j<4; j++)
            if(a[i] > a[j])
            {
                Officer temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    for(int i=0; i<4; i++)
        a[i].display();
    system("pause");
}