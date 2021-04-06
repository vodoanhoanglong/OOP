#include<iostream>
using namespace std;
class phanso
{
	private:
		int tu;
		int mau;
	public:
		phanso();
        phanso(int a, int b);
        phanso(const int &c);
		void nhap();
		void xuat();
        bool operator >=(phanso ps);
        bool operator <(phanso ps);
        bool operator >(phanso ps);
		
};
phanso::phanso()
{
	tu=1;
	mau=1;
}

phanso::phanso(int a, int b)
{
	tu=a;
	mau=b;
}  
phanso::phanso(const int &c)
{
	tu=c;
	mau=c;
} 
void phanso::nhap()
{
	cout<<"Nhap tu: ";
	cin>>tu;
	cout<<"Nhap mau: ";
	cin>>mau;
}
void phanso::xuat()
{
	if(this->mau==1)
		cout<<tu<<endl;
	else
		cout<<tu<<"/"<<mau<<endl;
}
bool phanso::operator >=(phanso ps)
{
    float a;
    a = this->tu*ps.mau - this->mau*ps.tu;
    if(a >= 0) 
        return true;
    return false;
}
bool phanso::operator >(phanso ps)
{
    float a;
    a = this->tu * ps.mau - this->mau * ps.tu;
    if(a > 0) 
         return true;
    return false;
}
bool phanso::operator <(phanso ps)
{
    float a;
    a = this->tu * ps.mau - this->mau * ps.tu;
    if(a < 0) 
        return true;
    return false;
}
int main()
{
    phanso ps1, ps2;
    cout<<"Nhap phan so thu 1: "<<endl; ps1.nhap(); 
    cout<<"Nhap phan so thu 2: "<<endl; ps2.nhap();
    ps1.xuat();
    ps2.xuat();
    if(ps1 >= ps2)
        cout<<"Ps1 >= Ps2"<<endl;
    else
        cout<<"Ps1 < Ps2"<<endl;

    
    phanso *p;
    p = new phanso[5];
    for(int i = 0; i < 5; i++)
    {
        cout<<"Nhap phan so thu "<<i<<": "<<endl;
        p[i].nhap();
    }
    phanso max, min;
    // Sử dụng phương thức gán mặc định
    max = p[0]; min = p[0]; 
    for(int i = 1; i<5; i++)
    {
        if(p[i] > max)
            max = p[i];
        else if(p[i] < min)
            min = p[i];
    }
    cout<<"Phan so lon nhat: ";
    max.xuat();
    cout<<"Phan so nho nhat: ";
    min.xuat();

    system("pause");
    return 0;
}