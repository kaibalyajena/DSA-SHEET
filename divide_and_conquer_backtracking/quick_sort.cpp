#include<iostream>
using namespace std;

int partition(int *arr,int l,int r){
    //choose the pivot index and find the pivot element
    int pivotIndex=l;
    int pivotElement=arr[pivotIndex];
    //count elements smaller than the pivot element to find the correct position of the pivot element in the sorted array
    int count=0;
    for(int i=l+1;i<=r;i++){
        if(arr[i]<pivotElement){
            count++;
        }
    }
    //place the pivot element at the correct position
    int correctIndex=l+count;
    swap(arr[pivotIndex],arr[correctIndex]);
    pivotIndex=correctIndex;
    //place smaller elements to the left of the pivot element and larger elements to the right of the pivot element
    int i=l;
    int j=r;
    while(i<pivotIndex&&j>pivotIndex){
        while(arr[i]<=pivotElement){
            i++;
        }
        while(arr[j]>pivotElement){
            j--;
        }
        if(i<pivotIndex&&j>pivotIndex){
            swap(arr[i],arr[j]);
        }
    }

    return pivotIndex;
}

void quickSort(int *arr,int l,int r){
    if(l>=r){
        return;
    }
    //partition the array and return the index of the sorted pivot element
    int pivot=partition(arr,l,r);
    //do recursion on the left and right part of the array
    quickSort(arr,l,pivot-1);
    quickSort(arr,pivot+1,r);
}

int main(){
    int arr[]={4,7,2,1,6,9,2};
    int n=7;
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}