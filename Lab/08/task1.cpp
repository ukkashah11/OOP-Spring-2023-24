#include <iostream>
using namespace std;
class Book{
    string title, author, publisher;
    public:
    Book(string t, string a, string p):title(t), author(a), publisher(p){}
    void display(){
        cout<<"Book title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Publisher: "<<publisher<<endl;
    }
};
class FictionBook:public Book{
    string genre, protagonist;
    public:
    FictionBook(string g, string p, string t, string a, string pub):genre(g), protagonist(p), Book(t,a,p){} 
    void displayDetails(){
        display();
        cout<<"Genre: "<<genre<<endl;
        cout<<"Protagonist: "<<protagonist<<endl;
    }
};
int main(){
    FictionBook fb("Sci-Fi", "Paul Atreides", "Dune", "Frank Herbert", "Chilton Books");
    fb.displayDetails();
    return 0;
}