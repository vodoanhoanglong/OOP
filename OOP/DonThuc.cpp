#include <iostream>
#include <cmath>
using namespace std;

class DonThuc
{
    private:
        float HeSo;
        int SoMu;
    public:
        DonThuc();
        DonThuc(float HeSo, int SoMu);
        ~DonThuc()
        {

        }
        friend istream &operator>>(istream &in, DonThuc &dt);
        friend ostream &operator<<(ostream &os, DonThuc &dt);
        bool Check(DonThuc dt);
        DonThuc operator+(DonThuc dt);
        DonThuc operator-(DonThuc dt);
        DonThuc operator*(DonThuc dt);
        DonThuc operator/(DonThuc dt);
        DonThuc operator!();
        DonThuc operator~();
        bool operator>(DonThuc dt);
 	    bool operator<(DonThuc dt);
 		bool operator==(DonThuc dt);
        DonThuc DaoHamBacK( int k);
};
DonThuc::DonThuc()
{
    HeSo = 1;
    SoMu = 1;
}
DonThuc::DonThuc(float HeSo, int SoMu)
{
    this->HeSo = HeSo;
    this->SoMu = SoMu;
}
istream &operator>>(istream &in, DonThuc &dt)
{
    cout<<"\nNhap he so: ";
    in>>dt.HeSo;
    cout<<"\nNhap so mu: ";
    in>>dt.SoMu;
    return in;
}
ostream &operator<<(ostream &os, DonThuc &dt)
{
    if(dt.HeSo==0){	
		cout<<0;
	}
	else if(dt.SoMu==0){
		cout<<dt.HeSo;
	}
	else if(dt.SoMu==1){
		cout<<dt.HeSo<<"x";
	}
	else{
		cout<<dt.HeSo<<"x^"<<dt.SoMu;
	}
	return os;
}
bool DonThuc::Check(DonThuc dt)
{
     if(dt.SoMu == SoMu)
         return true;
     return false;
}
DonThuc DonThuc::operator+(DonThuc dt)
{
    return DonThuc(this->HeSo+dt.HeSo, this->SoMu);
}
DonThuc DonThuc::operator-(DonThuc dt)
{
    return DonThuc(this->HeSo-dt.HeSo, this->SoMu);
}
DonThuc DonThuc::operator*(DonThuc dt)
{
    return DonThuc(this->HeSo*dt.HeSo, this->SoMu+dt.SoMu);
}
DonThuc DonThuc::operator/(DonThuc dt)
{
    return DonThuc(this->HeSo/dt.HeSo, this->SoMu-dt.SoMu);
}
DonThuc DonThuc::operator~()
{
    DonThuc temp;
	this->SoMu++;
	temp.SoMu=this->SoMu;
	temp.HeSo=this->HeSo/this->SoMu;
	return temp;
}
DonThuc DonThuc::operator!()
{
    DonThuc temp;
    temp.HeSo=this->HeSo*this->SoMu;
    temp.SoMu=this->SoMu-1;
    return temp;
}
bool DonThuc::operator>(DonThuc dt)
{
    float x, gt1, gt2;
	cout<<"\nNhap x: ";
	cin>>x;
    gt1=this->HeSo*pow(x, this->SoMu);
    gt2=dt.HeSo*pow(x, dt.SoMu);
    return (gt1>gt2)?true:false;
}
bool DonThuc::operator<(DonThuc dt)
{
    float x, gt1, gt2;
	cout<<"\nNhap x: ";
	cin>>x;
    gt1=this->HeSo*pow(x, this->SoMu);
    gt2=dt.HeSo*pow(x, dt.SoMu);
    return (gt1<gt2)?true:false;
}
bool DonThuc::operator==(DonThuc dt)
{
    float x, gt1, gt2;
	cout<<"\nNhap x: ";
	cin>>x;
    gt1=this->HeSo*pow(x, this->SoMu);
    gt2=dt.HeSo*pow(x, dt.SoMu);
    return (gt1==gt2)?true:false;
}
DonThuc DonThuc::DaoHamBacK(int k){
	DonThuc temp(this->HeSo,this->SoMu);
	for(int i=1;i<=k;i++){
		temp=!temp;
	}
	return temp;
}
int main()
{
    DonThuc dt1, dt2, T, A(2, 6), B;
    cout<<"\nNhap don thuc 1: "; cin>>dt1;
    cout<<"\nNhap don thuc 2: "; cin>>dt2;
    cout<<endl<<dt1;
    cout<<endl<<dt2;
    if(dt2.Check(dt1)==true){
         T = dt1 + dt2;
         cout<<endl<<T;
    }else
        cout<<endl<<dt1<<"+"<<dt2;
    
    
    
    if(dt2.Check(dt1)==true){
         T = dt1 - dt2;
         cout<<endl<<T;
    }
    else
        cout<<endl<<dt1<<"-"<<dt2;
    T=dt1*dt2;
    cout<<endl<<T;
    T=dt1/dt2;
    cout<<endl<<T;
    T=!dt1;
    cout<<endl<<T;
    if(dt1>dt2)
        cout<<"\ndt1 > dt2";
    else cout<<"\ndt1 <= dt2";
    B=A.DaoHamBacK(5);
    cout<<endl<<B;
}