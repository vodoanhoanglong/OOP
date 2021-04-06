#include <iostream>
#include <string>
using namespace std;

class SV
{
    protected:
        string room, fullName;
    public:
        virtual void input()
        {

        }
        virtual void display()
        {

        }
};
class SVSP : public SV
{
    private:
        string scholarship;
    public:
        void input();
        void display();
};

void SVSP::input()
{
    cout<<"Enter room: "<<endl;
    getline(cin, room);
    cout<<"Enter fullname: "<<endl;
    getline(cin, fullName);
    cout<<"Enter scholarship: "<<endl;
    getline(cin, scholarship);
}
void SVSP::display()
{
    cout<<"The room of pedagogical student is: "<<room<<endl;
    cout<<"Full name of pedagogical student is: "<<fullName<<endl;
    cout<<"The scholarship pedagogical student is: "<<scholarship<<endl;
}

class SVTC : public SV
{
    private: 
        long int tuition;
    public:
        void input();
        void display();
};

void SVTC::input()
{
    cout<<"Enter room: "<<endl;
    getline(cin, room);
    cout<<"Enter fullname: "<<endl;
    getline(cin, fullName);
    cout<<"Enter tuition: "<<endl;
    cin>>tuition;
}
void SVTC::display()
{
    cout<<"The room of TC student is: "<<room<<endl;
    cout<<"Full name of TC student is: "<<fullName<<endl;
    cout<<"The tuition TC student is: "<<tuition<<endl;
}

int main()
{
    SV *svsp = new SVSP;
    SV *svtc = new SVTC;
    svsp->input();
    svsp->display();
    svtc->input();
    svtc->display();
    system("pause");
}