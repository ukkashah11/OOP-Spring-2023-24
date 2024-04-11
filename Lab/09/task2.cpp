#include "iostream"
#include <cmath>
using namespace std;
float pi = 3.142;
class Shape{
    public:
    virtual double area () const = 0;
    virtual double perimeter() const = 0;
    virtual void displayProperties() const = 0;
};
class Circle: public Shape{
    float radius;
    public:
    Circle(float r): radius(r){}
    double area() const{
        return pi*(pow(radius, 2));
    }
    double perimeter() const{
        return 2*pi*radius;
    }
    void displayProperties()const{
        cout<<"Circle properties\n";
        cout<<"Radius: "<<radius<<endl;
        cout<<"Area: "<<area()<<endl;
        cout<<"Perimeter: "<<perimeter()<<endl;
    }
};
class Rectangle: public Shape{
    float width, length;
    public:
    Rectangle(float w, float l): width(w), length(l){}
    double area() const{
        return width*length;
    }
    double perimeter() const{
        return (2*width)+(2*length);
    }
    void displayProperties()const{
        cout<<"Rectangle properties\n";
        cout<<"Width: "<<width<<endl;
        cout<<"Length: "<<length<<endl;
        cout<<"Area: "<<area()<<endl;
        cout<<"Perimeter: "<<perimeter()<<endl;
    }
};
class Square: public Shape{
    float side;
    public:
    Square(float s): side(s){}
    double area() const{
        return pow(side,2);
    }
    double perimeter() const{
        return 4*side;
    }
    void displayProperties()const{
        cout<<"Square properties\n";
        cout<<"Side: "<<side<<endl;
        cout<<"Area: "<<area()<<endl;
        cout<<"Perimeter: "<<perimeter()<<endl;
    }
};
class Triangle:public Shape{
    float base, height, side3;
    public:
    Triangle(float s1, float s2, float s3):base(s1), height(s2), side3(s3){}
    double area() const{
        return 0.5*base*height;
    }
    double perimeter() const{
        return base+height+side3;
    }
    void displayProperties()const{
        cout<<"Triangle properties\n";
        cout<<"Base: "<<base<<endl;
        cout<<"Height: "<<height<<endl;
        cout<<"Side 3: "<<side3<<endl;
        cout<<"Area: "<<area()<<endl;
        cout<<"Perimeter: "<<perimeter()<<endl;
    }
};
class EquilateralTriangle: public Triangle{
    float side;
    public:
    EquilateralTriangle(float s):side(s), Triangle(s,s,s){}
     void displayProperties()const{
        cout<<"Equilateral Triangle properties\n";
        cout<<"Side: "<<side<<endl;
        cout<<"Area: "<<area()<<endl;
        cout<<"Perimeter: "<<perimeter()<<endl;
    }
    double area() const{
        return 0.5*pow(side,2);
    }
    double perimeter() const{
        return side+side+side;
    }
};
int main()
{
    Shape* shape = nullptr; //Shape ptr used for polymorphism
    string option;
    int choice;
    bool flag = true;
    while(flag){
    cout<<"Please select a shape: "<<endl;
    cout<<"1. Circle\n2. Rectangle\n3. Square\n4. Triangle\nEnter your choice: "<<endl;
    cin>>choice;
    switch(choice){
    case 1:
        float radius;
        cout<<"Enter radius of circle: ";
        cin>>radius;
        shape = new Circle(radius);
        shape->displayProperties();
        delete shape;
        cout<<"\nDo you want to calculate properties for another Shape? (yes/no): ";
        cin.ignore();
        getline(cin, option);
        if(option == "yes") flag = true;
        else flag = false;
        break;
    case 2:
        float length, width;
        cout<<"Enter length of rectangle: ";
        cin>>length;
        cout<<"Enter width of rectangle: ";
        cin>>width;
        shape = new Rectangle(length, width);
        shape->displayProperties();
        delete shape;
        cin.ignore();
        cout<<"\nDo you want to calculate properties for another Shape? (yes/no): ";
        getline(cin, option);
        if(option == "yes") flag = true;
        else flag = false;
        break;
    case 3:
        float side;
        cout<<"Enter length of square side: ";
        cin>>side;
        shape = new Square(side);
        shape->displayProperties();
        delete shape;
        cin.ignore();
        cout<<"\nDo you want to calculate properties for another Shape? (yes/no): ";
        getline(cin, option);
        if(option == "yes") flag = true;
        else flag = false;
        break;
    case 4:
        float side1,side2,side3;
        cout<<"Enter base of triangle: ";
        cin>>side1;
        cout<<"Enter height of triangle: ";
        cin>>side2;
        cout<<"Enter side 3 of triangle: ";
        cin>>side3;
        if(side1 == side2 && side2==side3 && side1==side3){
        shape = new EquilateralTriangle(side1);
        shape->displayProperties();
        delete shape;
        }
        else{
            shape = new Triangle(side1, side2, side3);
            shape->displayProperties();
            delete shape;
        }
        cin.ignore();
        cout<<"\nDo you want to calculate properties for another Shape? (yes/no): ";
        getline(cin, option);
        if(option == "yes") flag = true;
        else flag = false;
        break;
    defualt: cout<<"invalid input"<<endl;
    }
}
return 0;
}