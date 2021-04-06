//Bài 1.4, 1.8, 1.10
#include <iostream>
using namespace std;

class Vector
{
	private:
		int n;
		float *v;
    public:
	    Vector();
		Vector(int n, float *v);
		Vector(const int a);
		~Vector();
		void Input();
		void Output();
		Vector operator=(Vector vt);
		friend Vector operator+(Vector vt1, Vector vt2);
        friend Vector operator*(float k, Vector vt2);
		bool check(Vector vt);
};
Vector::Vector()
{
	n=0;
	v=NULL;
}
Vector::Vector(int n, float *v)
{
	this->n = n;
	this->v = new float[n];
	for(int i=0;i<n;i++)
		this->v[i]=v[i];
};
Vector::Vector(const int a)
{
	this->n = a;
	this->v = new float[n];
}
Vector::~Vector()
{
}
void Vector::Input()
{
	cout<<"Enter number elements: "<<endl;
	cin>>n;
	v = new float[n];
	for(int i=0; i<n; i++)
	{
		cout<<"Enter element " << i+1 << ": "; 
		cin >> v[i];
	}
}
void Vector::Output()
{
    for(int i=0; i<n; i++)
	    cout<<"Element "<<i+1<<": " << v[i] <<endl;	
}
Vector Vector::operator=(Vector vt)
{
	this->n=vt.n;
	this->v=new float[vt.n];
	for(int i=0; i<n; i++)
		this->v[i] = vt.v[i];
	return *this;
}
Vector operator+(Vector vt1, Vector vt2)
{
	Vector c=vt2;
	for(int i=0;i<vt2.n;i++)
		c.v[i]=vt1.v[i]+vt2.v[i];
	return c;
}
Vector operator*(float k, Vector vt2)
{
    Vector c=vt2;
	for(int i=0; i<vt2.n; i++)
        c.v[i] = k * vt2.v[i];
	return c;
}
bool Vector::check(Vector vt)
{
	if(this->n == vt.n)
	   return true;
	return false;
}
int main()
{
	float x[2] = {1,2};
	float y[2] = {3,4};
	float k;
	Vector a(2, x), b(2, y), c, d, e, f, g(2,x), h(2,y), z, m, n;
    c = a + b;
    c.Output();
	d.Input();
	e.Input();
	f = d+e;
	f.Output();
	cout<<"Gan:"<<endl;
	g = h;
	g.Output();
	cout<<"Nhan:"<<endl;
	cout<<"Nhap vao so thuc k:"<<endl;
	cin>>k;
	cout<<"Nhap vao 1 vector de * voi so thuc k:"<<endl;
    m.Input();
	cout<<"Xuat vector vua nhap: "<<endl;
	m.Output();
    z = k * m;
	cout<<"Xuat vector vua nhap * voi so thuc k: "<<endl;
	z.Output();
	cout<<"Kiem tra xem 2 vector co cung so phan tu hay k: "<<endl;
	if(a.check(z))
	{
	    cout<<"2 vector co cung so phan tu -> cong 2 vector lai: "<<endl;
        n = a + z;
		n.Output();
	}
	else cout<<"2 vector k cung so phan tu -> k cong 2 vector"<<endl;
    system("pause");
}
