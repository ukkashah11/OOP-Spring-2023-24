/*Syed Ukkashah Ahmed Shah
  23K-0055
*/
#include<iostream>
#include<cmath>
using namespace std;
class Square{
    float sideLength, area;
    static float allareas;
    void updateAllAreas(float a){
        allareas+=a;
    }
    public:
    float getSideLength() const {
        return sideLength;
    }

    float getArea() const {
        return area;
    }

    static float getAllAreas() {
        return allareas;
    }
    void setArea(const float side_len){
        area=pow(side_len,2);
        updateAllAreas(area);
    }
    Square(float sideLength):sideLength(sideLength){setArea(sideLength);}
    Square(){sideLength = 0;}
};
float Square:: allareas=0;
int main(){
    Square s1(2);
    cout<<"\n\nSquare 1\nSide length: "<<s1.getSideLength()<<"\nArea: "<<s1.getArea()<<"\nTotal Areas: "<<s1.getAllAreas();
    Square s2(5.5); 
    cout<<"\n\nSquare 2\nSide length: "<<s2.getSideLength()<<"\nArea: "<<s2.getArea()<<"\nTotal Areas: "<<s2.getAllAreas();
    Square s3(10.5);
    cout<<"\n\nSquare 3\nSide length: "<<s3.getSideLength()<<"\nArea: "<<s3.getArea()<<"\nTotal Areas: "<<s3.getAllAreas();
    return 0;
}