#include<iostream>
#include<string>
using namespace std;

class Student
{
    private:
        string room, fullName;
    public:
       Student();
       Student(string room, string fullName);
       ~Student();
       void input();
       void display();
};
Student::Student()
{
    this->room = "";
    this->fullName = "";
}
Student::Student(string room, string fullName)
{
    this->room = room;
    this->fullName = fullName;
}
Student::~Student()
{

}
void Student::input()
{
    cin.ignore(0);
    cout<<"Enter the student's class: "<<endl;
    getline(cin, room);
    cout<<"Enter the student's full name: "<<endl;
    getline(cin, fullName);
}
void Student::display()
{
    cout<<"The student's class is: "<<room<<endl;
    cout<<"The student's full name is: "<<fullName<<endl; 
}
class PedagogicalStudent : public Student
{
    private:
        float mediumScore;
        string scholarship;
    public:
        PedagogicalStudent();
        PedagogicalStudent(float mediumScore, string scholarship);
        ~PedagogicalStudent();
        void input();
        void display();
};
PedagogicalStudent::PedagogicalStudent()
{
    this->mediumScore = 0;
    this->scholarship = "";
}
PedagogicalStudent::PedagogicalStudent(float mediumScore, string scholarship)
{
    this->mediumScore = mediumScore;
    this->scholarship = scholarship;
}
PedagogicalStudent::~PedagogicalStudent()
{

}
void PedagogicalStudent::input()
{
    Student::input();
    cout<<"Enter the student's medium score: "<<endl;
    cin>>mediumScore;
    cout<<"Enter the student's scholarship: "<<endl;
    cin.ignore();
    getline(cin, scholarship);
}
void PedagogicalStudent::display()
{
    Student::display();
    cout<<"The student's medium score is: "<<mediumScore<<endl;
    cout<<"The student's scholarship is: "<<scholarship<<endl;
}
class BachelorStudent : public PedagogicalStudent
{ 
    private:
        float tuition;
    public:
        BachelorStudent();
        BachelorStudent(float tuition);
        ~BachelorStudent();
        void input();
        void display();
};
BachelorStudent::BachelorStudent()
{
    this->tuition = 0;
}
BachelorStudent::BachelorStudent(float tuition)
{
    this->tuition = tuition;
}
BachelorStudent::~BachelorStudent()
{

}
void BachelorStudent::input()
{
    PedagogicalStudent::input();
    cout<<"Enter the student's tuition: "<<endl;
    cin>>tuition;
}
void BachelorStudent::display()
{
    PedagogicalStudent::display();
    cout<<"The student's tuition is: "<<tuition<<endl;
}
int main()
{
    BachelorStudent *a = new BachelorStudent[3];
    for(int i=0; i<3; i++)
    {
        cout<<"Enter the student's " << i+1 << ": "<<endl;
        a[i].input();
        cout<<"Display the student's information " << i+1 <<endl;
        a[i].display();
    }
}
