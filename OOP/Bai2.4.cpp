#include <iostream>
#include <string>
using namespace std;

class Media
{
    private:
        string name;
        float price;
    public:
        Media();
        Media(string name, float price);
        ~Media();
        void input();
        void display();
};
Media::Media()
{
    this->name = "";
    this->price = 0;
}
Media::Media(string name, float price)
{
    this->name = name;
    this->price = price;
}
Media::~Media()
{

}
void Media::input()
{
    cout<<"Enter items name: "<<endl;
    getline(cin, name);
    cout<<"Enter items price: "<<endl;
    cin>>price;
}
void Media::display()
{
    cout<<"Items name is: "<<name<<endl;
    cout<<"Items price is: "<<price<<endl;
}
class Book : public Media
{
    private:
        int page;
        string author;
    public:
        Book();
        Book(int page, string author);
        ~Book();
        void input();
        void display();
};
Book::Book()
{
    this->page = 0;
    this->author = "";
}
Book::Book(int page, string author)
{
    this->page = page;
    this->author = author;
}
Book::~Book()
{

}
void Book::input()
{
    Media::input();
    cout<<"Enter the books page number: "<<endl;
    cin>>page;
    cin.ignore();
    cout<<"Enter the author of books: "<<endl;
    getline(cin, author);
}
void Book::display()
{
    Media::display();
    cout<<"The books page number is: "<<page<<endl;
    cout<<"The author of books is: "<<author <<endl;
}
class Video : public Media
{
    private:
        int runtime;
        float cost;
    public:
        Video();
        Video(int runtime, float cost);
        ~Video();
        void input();
        void display();
};
Video::Video()
{
    this->runtime = 0;
    this->cost = 0;
}
Video::Video(int runtime, float cost)
{
    this->runtime = runtime;
    this->cost = cost;
}
Video::~Video()
{

}
void Video::input()
{
    Media::input();
    cout<<"Enter the videos runtime: "<<endl;
    cin>>runtime;
    cout<<"Enter the videos cost: "<<endl;
    cin>>cost;
    cin.ignore();
}
void Video::display()
{
    Media::display();
    cout<<"The videos runtime is: "<<runtime<<endl;
    cout<<"The videos cost is: "<<cost<<endl;
}
int main()
{
    Book *a;
    Video *b;
    int n;
    cout<<"Enter number Book and Video: "<<endl;
    cin>>n;
    cin.ignore();
    a = new Book[n];
    b = new Video[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the book "<<i+1<<": "<<endl;
        a[i].input();
        cout<<"Enter the video "<<i+1<<": "<<endl;
        b[i].input();
    }
    for(int i=0; i<n; i++)
    {
        cout<<"The book "<<i+1<<": "<<endl;
        a[i].display();
        cout<<"The video "<<i+1<<": "<<endl;
        b[i].display();
    }
    system("pause");
}