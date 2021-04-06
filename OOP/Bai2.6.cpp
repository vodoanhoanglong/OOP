#include <iostream>
using namespace std;
#include <string>

class Printer
{
	private:
		string name;
		int number;
	public:
		void input(int q);
		void output(int q);
};
void Printer::input(int q)
{
	cout<<"Warehouse "<<q<<": "<<endl;
	cout<<"Enter printer name: "<<endl;
	getline(cin, name);
	cout<<"Enter printer number: "<<endl;
	cin>>number;
}
void Printer::output(int q)
{
	cout<<"Warehouse "<<q<<": "<<endl;
	cout<<"Printer name is: "<<name<<endl;
	cout<<"Printer number is: "<<number<<endl;
}
class Laser : public Printer
{
	private:
		float DPI;
	public:
		void input(int q);
		void output(int q);	
};
void Laser::input(int q)
{
	Printer::input(q);
	cout<<"Enter the printer's DPI: "<<endl;
	cin>>DPI;
	cin.ignore();
}
void Laser::output(int q)
{
	Printer::output(q);
	cout<<"The printer's DPI is: "<<DPI<<endl;
}
class ColorPrinter : public Printer
{
	private:
		string color;
	public:
		void input(int q);
		void output(int q);
};
void ColorPrinter::input(int q)
{
	Printer::input(q);
	cout<<"Enter the printer's color: "<<endl;
	cin.ignore();
	getline(cin, color);
}
void ColorPrinter::output(int q)
{
	Printer::output(q);
	cout<<"The printer's color is: "<<color<<endl;
}
class ColorLaser : public Laser, ColorPrinter
{
	public:
		void input(int q);
		void output(int q);
};
void ColorLaser::input(int q)
{
	Laser::input(q);
	ColorPrinter::input(q);
}
void ColorLaser::output(int q)
{
	Laser::output(q);
	ColorPrinter::output(q);
}
int main()
{
	ColorLaser *a = new ColorLaser[3];
	for(int i=0; i<3; i++)
		a[i].input(i+1);
	for(int i=0; i<3; i++)
		a[i].output(i+1);
    system("pause");
}