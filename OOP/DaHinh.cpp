#include <iostream>
#include <string>
using namespace std;
#include <vector>

class Staff
{
protected:
    string Full_Name;
    int Age;
    float Salary_Grade;
    bool Check;

public:
    Staff();
    ~Staff();

    virtual void Input();
    virtual void Output();
    virtual float Payroll() = 0;
    bool Get_Staff_Type()
    {
        return this->Check;
    }
    void Set_Staff_Type(bool check)
    {
        this->Check = check;
    }
    string Get_Name()
    {
        return this->Full_Name;
    }
};
Staff::Staff()
{
    Full_Name = "";
    Age = 0;
    Salary_Grade = 0;
}
Staff::~Staff()
{
}
void Staff::Input()
{
    cin.ignore();
    cout << "Enter full name: " << endl;
    getline(cin, Full_Name);
    cout << "Enter age: " << endl;
    cin >> Age;
    cout << "Enter salary grade: " << endl;
    cin >> Salary_Grade;
}
void Staff::Output()
{
    cout << "Full name: " << Full_Name << endl;
    cout << "Age: " << Age << endl;
}

class Official_Staff : public Staff
{
private:
    int Seniority;

public:
    Official_Staff();
    ~Official_Staff();
    void Input();
    void Output();
    float Payroll();
};
Official_Staff::Official_Staff()
{
    Seniority = 0;
}
Official_Staff::~Official_Staff()
{
}

void Official_Staff::Input()
{
    Staff::Input();
    cout << "Enter seniority: " << endl;
    cin >> Seniority;
}
void Official_Staff::Output()
{
    Staff::Output();
    cout << "Seniority: " << Seniority << endl;
    cout << "Salary: " << Payroll() << endl;
}

float Official_Staff::Payroll()
{
    return Salary_Grade * 1600;
}

class Interns_Staff : public Staff
{
private:
    int Day_To_Work;

public:
    Interns_Staff();
    ~Interns_Staff();
    void Input();
    void Output();
    float Payroll();
};
Interns_Staff::Interns_Staff()
{
    Day_To_Work = 0;
}
Interns_Staff::~Interns_Staff()
{
}
void Interns_Staff::Input()
{
    Staff::Input();
    cout << "Enter day to work: " << endl;
    cin >> Day_To_Work;
}
void Interns_Staff::Output()
{
    Staff::Output();
    cout << "Day to work: " << Day_To_Work << endl;
    cout << "Salary: " << Payroll() << endl;
}

float Interns_Staff::Payroll()
{
    return Salary_Grade * 1600 * 0.8;
}

class Company
{
private:
    vector<Staff *> Staff_List;

public:
    Company();
    ~Company();
    void Input();
    void Output();
    float Total_Salary();
    void Highest_Salary();
    void Sort();
    void Search();
};
Company::Company()
{
}
Company::~Company()
{
}
void Company::Input()
{
    int i = 1, choice;
    while (i)
    {
        system("cls");
        cout << "\n1. Enter official staff";
        cout << "\n2. Enter intern staff";
        cout << "\n3. Exit ";
        cout << "\nEnter your choice: ";
        cin >> choice;
        Staff *x;
        switch (choice)
        {
        case 1:
        {
            x = new Official_Staff;
            x->Input();
            x->Set_Staff_Type(true);
            Staff_List.push_back(x);
            break;
        }
        case 2:
        {
            x = new Interns_Staff;
            x->Input();
            x->Set_Staff_Type(false);
            Staff_List.push_back(x);
            break;
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "\nInvalid choice!!!" << endl;
            system("pause");
            break;
        }
        }
    }
}
float Company::Total_Salary()
{
    float sum = 0;
    for (int i = 0; i < Staff_List.size(); i++)
    {
        sum = sum + Staff_List[i]->Payroll();
    }
    return sum;
}
void Company::Output()
{
    int count1 = 0, count2 = 0;
    for (int i = 0; i < Staff_List.size(); i++)
    {
        if (Staff_List[i]->Get_Staff_Type() == true)
        {
            cout << "\nOfficial staff " << ++count1 << endl;
            Staff_List[i]->Output();
        }
    }
    for (int i = 0; i < Staff_List.size(); i++)
    {
        if (Staff_List[i]->Get_Staff_Type() == false)
        {
            cout << "\nIntern Staff " << ++count2 << endl;
            Staff_List[i]->Output();
        }
    }
}
void Company::Highest_Salary()
{
    float max;
    int temp = 0;
    max = Staff_List[0]->Payroll();
    for (int i = 1; i < Staff_List.size(); i++)
    {
        if (Staff_List[i]->Payroll() > max)
        {
            max = Staff_List[i]->Payroll();
            temp = i;
        }
    }
    Staff_List[temp]->Output();
}

void Company::Sort()
{
    for (int i = 0; i < Staff_List.size() - 1; i++)
    {
        for (int j = i + 1; j < Staff_List.size(); j++)
        {
            if (Staff_List[i]->Payroll() < Staff_List[j]->Payroll())
            {
                Staff *temp;
                temp = Staff_List[i];
                Staff_List[i] = Staff_List[j];
                Staff_List[j] = temp;
            }
        }
    }
}
void Company::Search()
{
    int count = 0;
    string search;
    cout << "Enter the full name of the staff to search: " << endl;
    cin.ignore();
    getline(cin, search);
    for (int i = 0; i < Staff_List.size(); i++)
    {
        if (search == Staff_List[i]->Get_Name())
        {
            count++;
            if (Staff_List[i]->Get_Staff_Type())
                cout << "\t\tThe staff to search is the official staff: " << endl;
            else
                cout << "\t\tThe staff to search is the intern staff: " << endl;
            Staff_List[i]->Output();
        }
    }
    if (count == 0)
        cout << "Could not find the staff in the list!!!" << endl;
}
int main()
{
    Company company;
    bool check;
    int choice;
    while (true)
    {
        system("cls");
        cout << "\n1. Enter information";
        cout << "\n2. Show information";
        cout << "\n3. Calculate the total salary";
        cout << "\n4. Find the staff with the highest salary";
        cout << "\n5. Sort by descending salary";
        cout << "\n6. Search the staff by full name";
        cout << "\n7. Exit ";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            company.Input();
            check = true;
            break;
        }
        case 2:
        {
            if (check)
            {
                company.Output();
                system("pause");
            }
            else
            {
                cout << "You have not entered the information!" << endl;
                system("pause");
            }
            break;
        }
        case 3:
        {
            cout << "\t\tThe total salary is: " << (size_t)company.Total_Salary() << endl;
            system("pause");
            break;
        }
        case 4:
        {
            cout << "\t\tThe staff with the highest salary: " << endl;
            company.Highest_Salary();
            system("pause");
            break;
        }
        case 5:
        {
            cout << "\t\tSort salary down by staff type: " << endl;
            company.Sort();
            company.Output();
            system("pause");
            break;
        }
        case 6:
            cout << "\t\tStaff search results by full name: " << endl;
            company.Search();
            system("pause");
            break;
        case 7:
        {
            system("cls");
            cout << "\t\tGood Bye!!!" << endl;
            cout << "\t";
            system("pause");
            exit(0);
        }
        default:
        {
            cout << "Invalid choice!!!" << endl;
            system("pause");
            break;
        }
        }
    }
    system("pause");
    return 0;
}