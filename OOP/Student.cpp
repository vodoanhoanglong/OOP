#include <iostream>
#include <string>
using namespace std;
class Student
{
    private:
        string id, fullname, sex;
        float scoreGT1, scoreTHDC, scoreTH, scoreDSTT, scoreCNXH, scoreGT2, scoreKTCT, scoreKNM, scoreLTNC, scoreVL, averagescorecoefficient4, averagescorecoefficient10;
    public:
        void input();
        void output();
};

void Student::input()
{
    cout << "\nEnter ID: ";
    cin.ignore(0);
    getline(cin, id);
    cout << "\nEnter full name: "; 
    cin.ignore(0);
    getline(cin, fullname);
    cout << "\nEnter sex: ";
    cin.ignore(0);
    getline(cin, sex);
    cout << "\nEnter score Giai tich 1: "; cin >> scoreGT1;
    cout << "\nEnter score Tin hoc dai cuong: "; cin >> scoreTHDC;
    cout << "\nEnter score Triet hoc: "; cin >> scoreTH;
    cout << "\nEnter score Dai so tuyen tinh: "; cin >> scoreDSTT;
    cout << "\nEnter score Chu nghia xa hoi: "; cin >> scoreCNXH;
    cout << "\nEnter score Giai tich 2: "; cin >> scoreGT2;
    cout << "\nEnter score Kinh te chinh tri: "; cin >> scoreKTCT;
    cout << "\nEnter score Ky nang mem: "; cin >> scoreKNM;
    cout << "\nEnter score Lap trinh nang cao: "; cin >> scoreLTNC;
    cout << "\nEnter score Vat ly: "; cin >> scoreVL; 
    averagescorecoefficient10 = ((scoreGT1+scoreTHDC+scoreTH+scoreDSTT+scoreGT2+scoreLTNC+scoreVL)*3 + (scoreCNXH+scoreKTCT+scoreKNM)*2)/27;
}
void Student::output()
{
    cout << "\nStudent Information: ";
    cout << "\nStudent id: " << id;
    cout << "\nStudent name: " << fullname;
    cout << "\nStudent sex: " << sex;
    cout << "\nScore Giai tich 1: " << scoreGT1;
    cout << "\nScore Tin hoc dai cuong: " << scoreTHDC;
    cout << "\nScore Triet hoc: " << scoreTH;
    cout << "\nScore Dai so tuyen tinh: " << scoreDSTT;
    cout << "\nScore Chu nghia xa hoi: " << scoreCNXH;
    cout << "\nScore Giai tich 2: " << scoreGT2;
    cout << "\nScore Kinh te chinh tri: " << scoreKTCT;
    cout << "\nScore Ky nang mem: " << scoreKNM;
    cout << "\nScore Lap trinh nang cao: " << scoreLTNC;
    cout << "\nScore Vat ly: " << scoreVL;
    cout << "\nAverage score coefficient 10: " << averagescorecoefficient10;
    float arr[10] = {scoreGT1, scoreTHDC, scoreTH, scoreDSTT, scoreCNXH, scoreGT2, scoreKTCT, scoreKNM, scoreLTNC, scoreVL}; 
    for(int i=0; i<10; i++)
    {
        if(arr[i] >= 8.5)
            arr[i] = 4;
        else if(arr[i] >= 7 && arr[i] <= 8.4)
            arr[i] = 3;
        else if(arr[i] >= 5.5 && arr[i] <= 6.9)
            arr[i] = 2;
        else if(arr[i] >= 5 && arr[i] <= 5.4)
            arr[i] = 1.5;
        else if(arr[i] >= 4 && arr[i] <= 4.9)
            arr[i] = 1;
        else if(arr[i] >= 3 && arr[i] <= 3.9)
            arr[i] = 0.5;
        else arr[i] = 0;
    }
    averagescorecoefficient4 = ((arr[0]+arr[1]+arr[2]+arr[3]+arr[5]+arr[8]+arr[9])*3 + (arr[4]+arr[6]+arr[7])*2)/27;
    cout << "\nAverage score coefficient 4: " << averagescorecoefficient4;
}

int main()
{
    Student student;
    student.input();
    student.output();
}
