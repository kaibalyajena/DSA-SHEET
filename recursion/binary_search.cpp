#include<iostream>
using namespace std;

int binSearch(int arr[],int target,int s,int e){
    if(s>e){
        return -1;
    }
    int m=s+e/2;
    if(arr[m]==target){
        return m;
    }
    if(arr[m]<target){
        return binSearch(arr,target,m+1,e);
    }
    return binSearch(arr,target,s,m-1);
}

int main(){
    int n=6;
    int arr[]={2,5,7,88,99,456};
    int target=456;
    cout<<binSearch(arr,target,0,n-1)<<endl;
    return 0;
}