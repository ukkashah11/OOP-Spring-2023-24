//added comments where I felt necessary to do so
#include <iostream>
#include <limits>
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
Book* findBook(string search, Book* books, int size){
        for(int i=0; i<size; i++){
            if(books[i].author == search || books[i].title == search){
                return &books[i]; //returns address of the book object if found
            }
        } 
    return nullptr; //returns null pointer if no Book object is found
}
void inputDetails(Book* b){
    cout<<"Book Title: ";
    std::cin.ignore();
    getline(cin,b->title);
    cout<<"Author: ";
    std::cin.ignore();
    getline(cin,b->author);
    cout<<"Year of publication: ";
    cin>>b->year;
    cout<<"Genre: ";
    std::cin.ignore();
    getline(cin,b->genre);
}
void addBook(Book*& books, int& size){ //function allocates memory for a new struct array, copies the book objects into the new array from the prevoius book array & prompts the user for the new Book details
    size++; 
    Book* newBooks = new Book[size]; //new keyword used to allocate memory for a new book
    for(int i=0; i<size-1; i++){
        newBooks[i] = books[i];  //this loop is used to copy the book objects into the dynamically memory allocated newBooks array
    }
    inputDetails(&newBooks[size-1]);
    delete[] books; //clearing the memory space allocated for the previous book struct array
    books = newBooks; // books now points to the addresss of newBooks
}
int main(){
  Book* books = nullptr;  
  int size = 0;
  int choice;
  string search;
  cout<<"Menu: "<<endl;
  do{
  cout<<"Press 1 to add a new book to the collection\nPress 2 to update existing book data\nPress 3 to search for a book\nPress 4 to exit"<<endl;
  cin>>choice;
  switch(choice){
    case 1:
    addBook(books,size);
    break;
    case 2:
    case 3:
        {
        string search;
            if (choice == 2) {
                cout << "Enter the name of the Author or the Title of the book to find a book and update it's data: ";
            } else { 
                cout << "Enter the name of the Author or the Title of the book: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // More reliable way to ignore leftovers like newline in the buffer
            getline(cin, search);
            Book* bookPtr = findBook(search, books, size);
            if (bookPtr != nullptr) {
                if (choice == 2) {
                    inputDetails(bookPtr);
                } else {
                    displayDetails(bookPtr);
                }
            } else {
                cout << "Book not found";
            }
        }
        break;
    case 4:
    delete[]books; //freeing the memory allocated for the Book struct array
    break;
    default: cout<<"Invalid Choice. Try Again";
  }
  }while(choice!=4);
  return 0;
} 