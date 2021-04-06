#include <iostream>
#include <string>
using namespace std;

class Printer
{
    protected:
        string name;
    public:
        virtual void input(){}
        virtual void display(){}
        bool operator>(Printer p1);
};
bool Printer::operator>(Printer p1)
{
    if(this->name > p1.name)
        return true;
    return false;
}
class Laser : public Printer
{
    private:
        int DPI;
    public:
        void input();
        void display();
};
void Laser::input()
{
    cout<<"Enter the printer name: "<<endl;
    getline(cin, name);
    cout<<"Enter the DPI of printer: "<<endl;
    cin>>DPI;
}
void Laser::display()
{
    cout<<"The printer name is: "<<name<<endl;
    cout<<"The printer DPI is: "<<DPI<<endl;
}
class ColorLaser : public Printer
{
    private:
        int color;
    public:
        void input();
        void display();
};
void ColorLaser::input()
{
    cin.ignore(1);
    cout<<"Enter the printer name: "<<endl;
    getline(cin, name);
    cout<<"Enter the color of printer: "<<endl;
    cin>>color;
}
void ColorLaser::display()
{
    cout<<"The printer name is: "<<name<<endl;
    cout<<"The printer color is: "<<color<<endl;
}
int main()
{
    Printer *laser = new Laser;
    Printer *colorlaser = new ColorLaser;
    laser->input();
    colorlaser->input();
    if(laser > colorlaser)
    {
        colorlaser->display();
        laser->display();
    }   
    else
    {
        laser->display();
        colorlaser->display();
    } 
    system("pause");
}