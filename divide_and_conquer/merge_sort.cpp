#include<iostream>
using namespace std;

void merge(int* arr,int l,int r){
    //find mid
    int mid=(l+r)/2;
    //length of the left array
    int llen=mid-l+1;
    //length of the right array
    int rlen=r-mid;
    //creating dynamic allocated memory for the left and right array (heap memory)
    int* larr=new int[llen];
    int* rarr=new int[rlen];
    //copying values of the left and right array from the main array;
    int k=l;
    for(int i=0;i<llen;i++){
        larr[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<rlen;i++){
        rarr[i]=arr[k++];
    }
    //merge 2 sorted arrays logic
    int lindex=0;
    int rindex=0;
    int mindex=l;
    while(lindex<llen && rindex<rlen){
        if(larr[lindex]<=rarr[rindex]){
            arr[mindex++]=larr[lindex++];
        }else{
            arr[mindex++]=rarr[rindex++];
        }
    }
    while(lindex<llen){
        arr[mindex++]=larr[lindex++];
    }
    while(rindex<rlen){
        arr[mindex++]=rarr[rindex++];
    }
}

void mergeSort(int* arr,int l,int r){
    if(l>=r){
        return;
    }
    int mid=(l+r)/2;
    //sort left part of the array
    mergeSort(arr,l,mid);
    //sort right part of the array
    mergeSort(arr,mid+1,r);
    //merge the 2 sorted arrays
    merge(arr,l,r);
}


int main(){
    int arr[]={4,7,2,1,6,9,2};
    int n=7;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}