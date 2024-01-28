#include<iostream>
using namespace std;
int main() {
int stds;50
int math, eng, sci;
float avg;
cout<< "Enter number of students: ";
cin>>stds;
for(int i=1; i<=stds; i++){
    cout<<"\nStudent "<<i<<"\n";
    cout<<"Enter math marks: ";
    cin>>math;
    cout<<"Enter english marks: ";
    cin>>eng;
    cout<<"Enter science marks: ";
    cin>>sci;
    cout<<"Total marks: "<<eng+math+sci<<"/300\n";
    avg = (eng+sci+math)/3;
    cout<<"Average Marks: "<<avg;
    if(avg<=100 && avg>=90){
        cout<<"\nGrade is A";
    }
    if(avg<=89 && avg>=80){
        cout<<"\nGrade is B";
    }
    if(avg<=79 && avg>=70){
        cout<<"\nGrade is C";
    }
    if(avg<=69 && avg>=60){
        cout<<"\nGrade is D";
    }
    if(avg<60){
        cout<<"\nGrade is F";
    }
}
  return 0;
}
