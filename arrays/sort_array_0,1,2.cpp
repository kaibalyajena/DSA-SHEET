#include <bits/stdc++.h>
using namespace std;

//by sorting
//tc 0(nlogn)
//sc 0(1)



//by count method
//tc 0(2n)
//sc 0(1)
void sortArray(int arr[], int n) {
    //count the frequency
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }
    //Replace the places in the original array:
    for (int i = 0; i < cnt0; i++) arr[i] = 0; // replacing 0's
    for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; // replacing 1's
    for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2; // replacing 2's
}


//by dutch national flag algorithm
// takes only single traversal of array
// The rules are the following:
// arr[0….low-1] contains 0. [Extreme left part]
// arr[low….mid-1] contains 1.
// arr[mid..high] is unsorted has 0,1,2
// arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
//tc 0(n)
//sc 0(1)
void sortArrayDutch(int arr[], int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main()
{
    int n = 6;
    int arr[] = {0, 2, 1, 2, 0, 1};
    sortArrayDutch(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}