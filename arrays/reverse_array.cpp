#include <bits/stdc++.h>
using namespace std;
  
//iterative solution
//initialize start as zero and end as n-1 and then repeatedly swap the start and end indices of the array while start is less than end
// tc 0(n)
// sc 0(1)
void reverseArray(int arr[], int start, int end)
{
    while(start<end){
        //swap(arr[start],arr[end]);
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }  
}     


//recursive solution
//initialize start as zero and end as n-1 and then swap the start and end indices of the array and then call the reverse function for the rest of the array
// tc 0(n)
// sc 0(n)
void reverseArrayRecur(int arr[],int start ,int end){
    if(start>=end){
        return;
    }
    swap(arr[start],arr[end]);
    reverseArrayRecur(arr,start+1,end-1);
}

void printArray(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   cout << arr[i] << " ";
   cout << endl;
} 
  
int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]); 
    printArray(arr, n);
    reverseArrayRecur(arr, 0, n-1);
    cout << "Reversed array is" << endl;
    printArray(arr, n);
    return 0;
}