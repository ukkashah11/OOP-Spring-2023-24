#include<iostream>
using namespace std;
class Stats{
  int x;
  public:
  Stats(int a): x(a){}
  bool operator == (const Stats &stats){
    if(this->x == stats.x) return true;
    else return false;
  }
  bool operator > (const Stats & stats){
    if(this->x > stats.x)return true;
    else return false;
  }
  bool operator < (const Stats &stats){
    if(this->x < stats.x) return true;
    else return false;
  }
};
int main() {
	Stats s1(3), s2(5);
  if(s1 == s2) cout<<"x values of s1 & s2 are equal"<<endl;
  if(s1 > s2) cout<<"x value of s1 > x value of s2"<<endl;
  if(s1 < s2) cout<<"x value of s1 < x value of s2"<<endl;
}

