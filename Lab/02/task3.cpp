#include <iostream>
using namespace std;
bool hasSubsetSum(int arr[], int size, int targetSum){
    if(targetSum==0){
        return true;
    }
    if(targetSum!=0 && size==0){
        return false;
    }
    if(targetSum>arr[size-1]){
        hasSubsetSum(arr,size-1,targetSum);
    }
     return hasSubsetSum(arr, size - 1, targetSum) || 
           hasSubsetSum(arr, size - 1, targetSum - arr[size - 1]);
    
}
int main(){
    int arr[] = {2,4,5,1,20,13,6};
    int target = 23;
    if(hasSubsetSum(arr, sizeof(arr)/4, target)){
        cout<<"Subset summing to "<<target<<" exists";
    }
    else{
        cout<<"Subset doesn't exist";
    }
    return 0;
}