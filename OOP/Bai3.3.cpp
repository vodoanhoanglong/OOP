#include <iostream>
using namespace std;

class Item
{
    protected:
        string itemName;
    public:
        virtual void input()
        {

        }
        virtual void display()
        {

        }
};
class Computer : public Item
{
    private:
        int speed;
    public:
        void input();
        void display();
};
void Computer::input()
{
    cout<<"Enter items name: "<<endl;
    getline(cin, itemName);
    cout<<"Enter speed of the computer: "<<endl;
    cin>>speed;
}
void Computer::display()
{
    cout<<"The items name is: "<<itemName<<endl;
    cout<<"The computer has speed is: "<<speed<<endl;
}
class Printer : public Item
{
    private:
        int DPI;
    public:
        void input();
        void display();
};
void Printer::input()
{
    cin.ignore(1);
    cout<<"Enter items name is: "<<endl;
    getline(cin, itemName);
    cout<<"Enter the DPI of printer: "<<endl;
    cin>>DPI;
}
void Printer::display()
{
    cout<<"The items name is: "<<itemName<<endl;
    cout<<"The DPI of printer is: "<<DPI<<endl;
}
int main()
{
    Item *computer = new Computer;
    Item *printer = new Printer;
    computer->input();
    computer->display();
    printer->input();
    printer->display();
    system("pause");
}