#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Movie
{
    private:
        string movieName;
        double adultTicket, childTicket, numberAdultTicket, numberChildTicket, grossAmount, Donate, netSale;
    public: 
        void inPut();
        void outPut();
        
};
int main()
{
    Movie movie;
    for(int i=0; i<20; i++)
        cout << setfill('*') << "_" << setw(2);
    movie.inPut();
    for(int i=0; i<20; i++)
        cout << setfill('*') << "_" << setw(2);
    movie.outPut();
    
}
void Movie::inPut()
{
    cout << "\nEnter movie name: "; cin.ignore(0); getline(cin, movieName);
    cout << "\nEnter price of an adult ticket price: "; cin >> adultTicket;
    cout << "\nEnter price of a child ticket price: "; cin >> childTicket;
    cout << "\nEnter the number of adult tickets sold: "; cin >> numberAdultTicket;
    cout << "\nEnter the number of child tickets sold: "; cin >> numberChildTicket;
    grossAmount = adultTicket*numberAdultTicket + childTicket*numberChildTicket;
    Donate = (grossAmount * 10/100);
    netSale = grossAmount - Donate;
}
void Movie::outPut()
{
    cout << "\nMovie Name: " << movieName;
    cout << "\nNumber of Tickets Sold: " << numberAdultTicket+numberChildTicket;
    cout << "\nGross Amount: "  << fixed << setprecision(2) <<grossAmount;
    cout << "\nPercentage of Gross Amount Donated: 10.00%"; 
    cout << "\nAmount Donated: " << fixed << setprecision(2) << Donate;
    cout << "\nNet Sale: "  << fixed << setprecision(2) << netSale; 
}