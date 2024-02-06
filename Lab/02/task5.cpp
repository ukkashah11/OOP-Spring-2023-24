#include <iostream>
#include<limits>
using namespace std;
struct Product{
    string name;
    int quantity;
    float price;
    int id=0;
};
void inputDetails(Product* p){
    cout<<"Product Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, p->name);
    cout<<"Product stock: ";
    cin>>p->quantity;
    cout<<"Product price: ";
    cin>>p->price;
    if(p->id ==0){
    cout<<"Product ID: ";
    cin>>p->id;
    }
}
void addProduct(int& size, Product*& prods){
    size++;
    Product* catalog = new Product[size];
    for(int i=0; i<size-1; i++){
        catalog[i] = prods[i];
    }
    delete[] prods;
    inputDetails(&catalog[size-1]);
    prods = catalog;
}
void displayDetails(Product* p){
    cout<<"\nProduct Name: "<<p->name<<endl;
    cout<<"Price: "<<p->price<<endl;
    cout<<"Quantity: "<<p->quantity<<endl;
    cout<<"ID: "<<p->id<<endl;
                       
}
Product* findProduct(Product p[], int size, int ID){
    for(int i=0; i<size; i++){
        if(p[i].id == ID){
            return &p[i];
        }
    }
    return nullptr;
}
int main(){
    Product* products = nullptr;
    int size = 0;
    int choice;
    cout<<"MENU"<<endl;
    do{
    cout<<"\nPress 1 to add a new product to the catalog\nPress 2 to update existing product data\nPress 3 to search for a product\nPress 4 to exit"<<endl;
  cin>>choice;
  switch(choice){
    case 1:
    addProduct(size, products);
    break;
    case 2:
    case 3:
        {
        int search;
            if (choice == 2) {
                cout << "Enter the ID of the Prodct to find a Product and update it's data: ";
            } else { 
                cout << "Enter the ID of the Product: ";
            }
            cin>>search;
            Product* prodPtr = findProduct(products,size,search);
            if (prodPtr != nullptr) {
                if (choice == 2) {
                    inputDetails(prodPtr);
                } else {
                    displayDetails(prodPtr);
                }
            } else {
                cout << "\nProduct not found"<<endl;
            }
        }
        break;
    case 4:
    delete[]products; //freeing the memory allocated for the Product struct array
    break;
    default: cout<<"Invalid Choice. Try Again";
  }
}while(choice!=4);
return 0;
}
  



