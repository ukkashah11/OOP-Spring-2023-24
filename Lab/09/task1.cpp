#include "iostream"
#include <cmath>
using namespace std;
float pi = 3.142;
class Shape{
    public:
    //calculates area of circle
    float area(float radius){
        return pi*(pow(radius, 2));
    }
    //calculates area of rectangle
    float area(float length, float width){
        return length*width;
    }
    //calculates area of triangle
    float area(float factor, float base, float height){
        return factor*base*height;
    }
    //calculates perimeter of circle
    float perimeter(float radius){
        return 2*pi*radius;
    }
    //calculates perimeter of rectangle
    float perimeter(float length, float width){
        return (2*length)+(2*width);
    }
    //calculates perimeter of triangle
    float perimeter(float side1, float side2, float side3){
        return side1+side2+side3;
    }
};
int main(){
    Shape shape;
    // Circle with radius 5
    float circleRadius = 5;
    cout << "Circle with radius " << circleRadius << endl;
    cout << "Area: " << shape.area(circleRadius) << endl;
    cout << "Perimeter: " << shape.perimeter(circleRadius) << "\n" << endl;

    // Rectangle with length 4 and width 6
    float rectangleLength = 4, rectangleWidth = 6;
    cout << "Rectangle with length " << rectangleLength << " and width " << rectangleWidth << endl;
    cout << "Area: " << shape.area(rectangleLength, rectangleWidth) << endl;
    cout << "Perimeter: " << shape.perimeter(rectangleLength, rectangleWidth) << "\n" << endl;

    // Triangle with base 3, height 4, and sides 3, 4, 5 (right-angled triangle)
    float factor = 0.5, triangleBase = 3, triangleHeight = 4;
    float triangleSide1 = 3, triangleSide2 = 4, triangleSide3 = 5;
    cout << "Triangle with base " << triangleBase << ", height " << triangleHeight;
    cout << " and sides " << triangleSide1 << ", " << triangleSide2 << ", " << triangleSide3 << endl;
    cout << "Area: " << shape.area(factor, triangleBase, triangleHeight) << endl;
    cout << "Perimeter: " << shape.perimeter(triangleSide1, triangleSide2, triangleSide3) << endl;

    return 0;
}
