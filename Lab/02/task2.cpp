#include <iostream>
#include <cstring>
using namespace std;
struct Book{
    string title;
    string author;
    string genre;
    int year;
};
void displayDetails(Book* b){
    cout<<"Book Title: "<<b->title<<endl;
    cout<<"Author: "<<b->author<<endl;
    cout<<"Year of publication: "<<b->year<<endl;
    cout<<"Genre: "<<b->genre<<endl;
}
Book* findBook(string find, Book* books, int size){
        for(int i=0; i<size; i++){
            if(books[i].author == find || books[i].title == find){
                return &books[i];
            }
        }
    return nullptr;
}
void inputDetails(Book* b){
    cout<<"Book Title: ";
    cin>>
}
void addBook(Book*& books, int& size){
    size++; 
    Book* newBooks = new Book[size]; //new keyword used to allocate memory for a new book
    for(int i=0; i<size-1; i++){
        newBooks[i] = books[i];  //this loop is used to copy the book objects into the dynamically memory allocated newBooks array
    }

}
int main(){
  Book* books = nullptr;  
  int choice;
  cout<<"Menu: "<<endl;
  cout<<"Press 1 to input new book\nPress 2 to update existing book data\n";
  cin>>choice;
  switch(choice){
    case 1:
    

  }
  return 0;
} 