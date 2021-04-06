#include <iostream>
using namespace std;
#define MAX 10
class employee
{
    private:
       int id;
       char name[30];
       float salary;
    public:
        void getDetails(void);
        void putDetails(void);
        float paySocialInsurance();
};
class Person{
    private:
       std::string id;
       std::string name;
    public:
        Person(){ //default constructor
            this->id = "000";
            this->name = "No name";
        }
        Person(std::string id, std::string name){ //arguments constructor
            this->id = id;
            this->name = name;
        }
        Person(const Person& orther){ //copy constructor
            this->id = orther.id + "-person_orther";
            this->name = orther.name;
        }
        Person&operator=(const Person& orther){ //assignment operator
            this->id = orther.id + "-person_orther";
            this->name = orther.name;
            return *this;
        }
        void setId(std::string id);
        std::string getId();
};
void Person::setId(std::string id){
    this->id = id;
}
std::string Person::getId(){
    return this->id;
}
void employee::getDetails(void)
{
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter salary: ";
    cin >> salary;
}
float employee::paySocialInsurance()
{
    
   float socialInsurance = 0;
    if(salary < 5000000)
        socialInsurance = (salary*1.3)/100;
    else
        socialInsurance = (salary*1.5)/100;   
    return socialInsurance;
}
void employee::putDetails(void)
{
    cout << fixed;
    cout.precision(0);
    cout << "ID: " << id << "\nName: " << name << "\nSalary: " << salary << "\nSocial insurance premium: " << paySocialInsurance() << endl;
}
int main()
{
    employee employee[MAX];
    int n, loop;
    cout << "Enter total number of employee: ";
    cin >> n;
    for(loop=0; loop<n; loop++)
    {
        cout << "Enter details of employee " << loop+1 << ":\n";
        employee[loop].getDetails();
    }
    for(loop=0; loop<n; loop++)
    {
        cout << "Details of employee " << loop+1 << ":\n";
        employee[loop].putDetails();
    }
    Person person1;
    Person person2("001", "Minh Anh");
    person2.setId("005");
    std::cout<<person2.getId();
    Person person3(person2);
    Person person4 = person2;
    Person person5;
    person5 = person2;
    return 0;
}

