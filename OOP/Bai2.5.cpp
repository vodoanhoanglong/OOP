#include <iostream>
#include <string>
using namespace std;

class MyAddress
{
    private: 
        string province, district;
    public:
        MyAddress();
        MyAddress(string province, string district);
        ~MyAddress();
        void input();
        void display();
};
MyAddress::MyAddress()
{
    this->province = "";
    this->district = "";
}
MyAddress::MyAddress(string province, string district)
{
    this->province = province;
    this->district = district;
}
MyAddress::~MyAddress()
{

}
void MyAddress::input()
{
    cout<<"Enter your province: "<<endl;
    getline(cin, province);
    cout<<"Enter your district: "<<endl;
    getline(cin, district);
}
void MyAddress::display()
{
    cout<<"Your province is: "<<province<<endl;
    cout<<"Your district is: "<<district<<endl;
}
class Person : public MyAddress
{
    private:
       string name;
       long int phone;
    public:
        Person();
        Person(string name, long int phone);
        ~Person();
        void input();
        void display();
};
Person::Person()
{
    this->name = "";
    this->phone = NULL;
}
Person::Person(string name, long int phone)
{
    this->name = name;
    this->phone = phone;
}
Person::~Person()
{

}
void Person::input()
{
    MyAddress::input();
    cout<<"Enter full name: "<<endl;
    getline(cin, name);
    cout<<"Enter phone: "<<endl;
    cin>>phone;
    cin.ignore(1);
}
void Person::display()
{
    MyAddress::display();
    cout<<"Full name is: "<<name<<endl;
    cout<<"Phone is: "<<phone<<endl;
}
class Officer : public Person
{
    private:
        float salary;
    public:
        Officer();
        ~Officer();
        void input();
        void display();
        bool operator>(Officer of);
};
Officer::Officer()
{
    this->salary = 0;
}
Officer::~Officer()
{

}
void Officer::input()
{
    Person::input();
    fflush(stdin);
    cout<<"Enter salary: "<<endl;
    cin>>salary;
}
void Officer::display()
{
    Person::display();
    cout<<"Salary is: "<<salary<<endl;
}
bool Officer::operator>(Officer of)
{
    if(this->salary > of.salary)
        return true;
    return false;        
}
int main()
{
    Officer *a = new Officer[4];
    for(int i=0; i<4; i++)
    {
        cout<<"-Enter Officer " << i+1<<": "<<endl;
        a[i].input();
        cin.ignore();
    }
    for(int i=0; i<4-1; i++)
       for(int j=1; j<4; j++)
           if(a[i] > a[j])
           {
               Officer temp = a[i];
               a[i] = a[j];
               a[j] = temp;
           }
    for(int i=0; i<4; i++)
    {
        cout<<"-Officer "<<i+1<<": "<<endl;
        a[i].display();
    }
    system("pause");
}