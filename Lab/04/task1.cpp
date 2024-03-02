/*Syed Ukkashah Ahmed Shah
  23K-0055
*/
#include <iostream>
#include <string>
using namespace std;
class Book{
    private:
    string name, author, ISBN;
    int pages, read;
    public:
    bool isAllDigits(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
    }
     void setName(string newName) {
        name = newName;
     }
    
    void setAuthor(string newAuthor) {
        author = newAuthor;
    }
    void setISBN(const string& newISBN) {
        if(isAllDigits(newISBN) == true && newISBN.size() == 13){
        ISBN = newISBN;
        }
        else{
            cout<<"Invalid input"<<endl;
        }
    }
    void setPages(int newPages) {
        pages = newPages;
    }
    void setRead(int newRead) {
        if(newRead<=getPages()){
        read = newRead;
        if(newRead==getPages()){
           cout<<"Book finished"<<endl;
        }
        }
        else{
            cout<<"Invalid input"<<endl;
        }
    }
    string getName() const {
        return name;
    }
    string getAuthor() const {
        return author;
    }
    string getISBN() const {
        return ISBN;
    }
    int getPages() const {
        return pages;
    }
    int getRead() const {
        return read;
    }
   Book(string newName, string newAuthor, string newISBN, int newPages, int newRead){
    setName(newName);
    setAuthor(newAuthor);
    setISBN(newISBN);
    setPages(newPages);
    setRead(newRead);
   }    
};
int main(){
    Book book("abc dhf", "ukkashah", "1234567890123", 200, 5);
    cout << "Book Name: " << book.getName() << endl;
    cout << "Author: " << book.getAuthor() << endl;
    cout << "ISBN: " << book.getISBN() << endl;
    cout << "Pages: " << book.getPages() << std::endl;
    book.setRead(300); 
    book.setRead(200);
}