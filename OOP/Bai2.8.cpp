#include <iostream>
#include <string>
using namespace std;
class MyTime
{
    private:
        int hours, minute, seconds;
    public:
        void input();
        void display();
};
void MyTime::input()
{
    cout<<"Enter hours: "<<endl;
    cin>>hours;
    cout<<"Enter minute: "<<endl;
    cin>>minute;
    cout<<"Enter seconds: "<<endl;
    cin>>seconds;
}
void MyTime::display()
{
    cout<<hours<<":"<<minute<<":"<<seconds<<endl;
}
class MyDate
{
    private:
       int day, month, year;
    public:
       void input();
       void display();
};
void MyDate::input()
{
    cout<<"Enter day: "<<endl;
    cin>>day;
    cout<<"Enter month: "<<endl;
    cin>>month;
    cout<<"Enter year: "<<endl;
    cin>>year;
}
void MyDate::display()
{
    cout<<day<<"-"<<month<<"-"<<year<<endl;
}
class MyFile : public MyTime, MyDate
{
    private:
        string fileName;
        int fileSize;
    public:
        void input();
        void display();
        bool operator>(MyFile mf);
};
void MyFile::input()
{
    MyTime::input();
    MyDate::input();
    cout<<"Enter file name: "<<endl;
    cin.ignore();
    getline(cin, fileName);
    cout<<"Enter file size: "<<endl;
    cin>>fileSize;
}
void MyFile::display()
{
    MyTime::display();
    MyDate::display();
    cout<<"File name is: "<<fileName<<endl;
    cout<<"File size is: "<<fileSize<<endl;
}
bool MyFile::operator>(MyFile mf)
{
    if(this->fileSize > mf.fileSize)
        return true;
    return false;
}
int main()
{
    MyFile *a = new MyFile[5];
    for(int i=0; i<5; i++)
    {
        cout<<"-Enter file "<<i+1<<": "<<endl;
        a[i].input();
    }
    for(int i=0; i<5-1; i++)
        for(int j=1; j<5; j++)
           if(a[j] > a[i])
           {
               MyFile temp = a[i];
               a[i] = a[j];
               a[j] = temp;
           }
    for(int i=0; i<5; i++)
    {
        cout<<"Information file "<<i+1<<": "<<endl;
        a[i].display();
    }
    system("pause");
}