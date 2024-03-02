
#include <iostream>
using namespace std;
int main(){
    int height[] = {1,8,6,2,5,4,8,3,7};
    int i=0;
    int distance;
    int j=sizeof(height)/4 - 1;
    int max = 0;
    while(i<j){
        if(j== i+1){
            j=sizeof(height)/4 -1;
            i++;
        }
        int base = j-i;
        if(height[i]<height[j]){
            distance = height[i];
        }
        if(height[i]>height[j]){
            distance = height[j];
        }
        if(height[i] == height[j]){
            distance = height[i];
        }
        if(max<(distance*base)){
            max = distance*base;
        }
        j--;
    }
    cout<<"Max amount of water the container can hold is "<<max<<endl;
    return 0;
}