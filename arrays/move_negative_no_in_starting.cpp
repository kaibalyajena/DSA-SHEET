#include<bits/stdc++.h>
using namespace std;

//by sorting
//tc 0(nlogn)
//sc 0(1) or 0(n)


//by partition (quicksort)
//tc 0(n)
//sc 0(1)
void rearrange(int arr[], int n)
{
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            if(i!=j){
                swap(arr[i],arr[j]);
            }
            j++;
        }
    }
}


//by 2 pointer approach
//approach
// Check If the left and right pointer elements are negative then simply increment the left pointer.
// Otherwise, if the left element is positive and the right element is negative then simply swap the elements, and simultaneously increment and decrement the left and right pointers.
// Else if the left element is positive and the right element is also positive then simply decrement the right pointer.
// Repeat the above 3 steps until the left pointer ≤ right pointer.
//tc 0(n)
//sc 0(1)
void shiftall(int arr[], int left,int right)
{
  while(left<=right){
    if(arr[left]<0&&arr[right]<0){
        left+=1;
    }else if(arr[left]>0&&arr[right]>0){
        right-=1;
    }else if(arr[left]<0&&arr[right]>0){
        left+=1;
        right-=1;
    }else{
        swap(arr[right],arr[left]);
        left+=1;
        right-=1;
    }
  }
}


//by dutch national flag algorithm
//2 pointers high and low needed
// ar[1…low-1] negative integers
// ar[low…high] unknown
// ar[high+1…N] positive integers
//tc 0(n)
//sc 0(1)
void shiftDutch(int arr[],int n){
    int low=0,high=n-1;
    while(low<=high){
        if(arr[low]<0){
            low+=1;
        }else{
            swap(arr[low],arr[high]);
            high-=1;
        }
    }
}



void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // rearrange(arr, n);
    //shiftall(arr,0,n-1);
    shiftDutch(arr,n);
    printArray(arr, n);
    return 0;
}