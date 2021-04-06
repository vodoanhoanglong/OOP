#include <iostream>
#include <string>
using namespace std;

class MyAttr
{
    private:
       int Attr;
    public:
       MyAttr();
       ~MyAttr();
       void input();
       void display(); 
};
MyAttr::MyAttr()
{
    this->Attr = 1;
}
MyAttr::~MyAttr()
{

}
void MyAttr::input()
{
    cout<<"Enter Attr: ";
    cin>>Attr;
}
void MyAttr::display()
{
    cout<<"Attr is: "<< Attr<<endl;
}

class MyDate
{
    private:
        int day, month, year;
    public:
        MyDate();
        MyDate(int day, int month, int year);
        ~MyDate();
        bool operator>(MyDate md);
        void input();
        void display();
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

class MyFile: public MyAttr, MyDate
{
    private:
       string fileName;
       int fileSize;
    public:
        MyFile();
        MyFile(string fileName, int fileSize);
        ~MyFile();
        void input();
        void display();
        bool operator>(MyFile mf);
};
MyFile::MyFile()
{
    this->fileName = "No Name";
    this->fileSize = 1;
}
MyFile::MyFile(string fileName, int fileSize)
{
    this->fileName = fileName;
    this->fileSize = fileSize;
}
MyFile::~MyFile()
{

}
void MyFile::input()
{
    MyAttr::input();
    MyDate::input();
    cout<<"Enter file name: "<<endl;
    cin.ignore();
    getline(cin, fileName);
    cout<<"Enter file size: "<<endl;
    cin>>fileSize;
}
void MyFile::display()
{
    MyAttr::display();
    MyDate::display();
    cout<<"File name: "<<fileName<<endl;
    cout<<"File size: "<<fileSize<<endl;
}
bool MyFile::operator>(MyFile mf)
{
    return MyDate::operator>(mf);
}
int main()
{
    MyFile *a = new MyFile[4];
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
                MyFile temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    for(int i=0; i<4; i++)
        a[i].display();
    system("pause");
}