#include <iostream>
#include <string>
using namespace std;

void input(string str[], int &n);
void display(string str[], int n);
string findMax(string str[], int n);

int main()
{
    int n;
    string str[n];
    input(str, n);
    display(str, n);
    system("pause");
}

void input(string str[], int &n)
{
    cout<<"Enter the number of strings: ";
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the strings "<<i+1<<": "<<endl;
        getline(cin, str[i]);
    }
}
string findMax(string str[], int n)
{
    string max = str[0];
    for(int i=0; i<n; i++)
        if(str[i] > max)
           max = str[i];
    return max;
}
void display(string str[], int n)
{
    string max = findMax(str, n);
    cout<<"Value max is: "<<max<<endl;
}