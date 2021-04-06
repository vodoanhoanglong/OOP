#include <iostream>
#include <string>
using namespace std;
class Media
{
    protected:
        string name;
        float cost;
    public:
        Media();
        virtual void input(){}
        virtual void display(){}
};
Media::Media()
{
    this->name = "";
    this->cost = 0;
}
class Book : public Media
{
    private:
        int page;
        string author;
    public: 
        Book();
        void input();
        void display();
};
Book::Book()
{
    this->page = 0;
    this->author = "";
}
void Book::input()
{
    cout<<"Enter the media name: "<<endl;
    getline(cin, name);
    cout<<"Enter the media cost: "<<endl;
    cin>>cost;
    cout<<"Enter the book page: "<<endl;
    cin>>page;
    cout<<"Enter the author of book: "<<endl;
    cin.ignore(1);
    getline(cin, author);
}
void Book::display()
{
    cout<<"The media name is: "<<name<<endl;
    cout<<"The media cost is: "<<cost<<endl;
    cout<<"The book page is: "<<page<<endl;
    cout<<"The author of book is: "<<author<<endl;
}
class Video : public Media
{
    private:
        int runtime;
        float price;
    public:
        Video();
        void input();
        void display();
};
Video::Video()
{
    this->runtime = 0;
    this->price = 0;
}
void Video::input()
{
    cout<<"Enter the media name: "<<endl;
    cin.ignore(0);
    getline(cin, name);
    cout<<"Enter the media cost: "<<endl;
    cin>>cost;
    cout<<"Enter the video runtime: "<<endl;
    cin>>runtime;
    cout<<"Enter the video price: "<<endl;
    cin>>price;
}
void Video::display()
{
    cout<<"The media name is: "<<name<<endl;
    cout<<"The media cost is: "<<cost<<endl;
    cout<<"The video runtime is: "<<runtime<<endl;
    cout<<"The video price is: "<<price<<endl;
}
int main()
{
    Media *book = new Book;
    Media *video = new Video;
    book->input();
    book->display();
    video->input();
    video->display();
    system("pause");
}