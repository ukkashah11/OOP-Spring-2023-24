
#include <iostream>
using namespace std;
void findTarget(int size, int arr[], int target){
    int flag=0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(arr[i] + arr[j] == target && flag ==0){
                cout<<arr[i]<<"+"<<arr[j]<<"="<<target<<endl;
                cout<<"Because"<<" arr["<<i<<"]+"<<"arr["<<j<<"]="<<target<<" we return ["<<i<<","<<j<<"]"<<endl;
                flag=1;
            }
        }
    }
}
int main(){
    cout<<"Enter size of array: ";
    int size, target;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++){
        cout<<"Enter element " << i+1 <<": ";
        cin>>arr[i];
    }
    cout<<"Enter target: ";
    cin>>target;
    findTarget(size, arr, target);
    return 0;
}
