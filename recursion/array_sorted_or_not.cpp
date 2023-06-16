#include<iostream>
using namespace std;

bool sorted(int arr[],int n){
    if(n<=1){
        return true;
    }
    return sorted(arr,n-1)&&(arr[n-1]>=arr[n-2]);
}

int main(){
    int arr[]={1,9,5,7,89};
    int n=5;
    cout<<sorted(arr,n)<<endl;
    return 0;
}
