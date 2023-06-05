// Input: 
// n = 4, arr1[] = [1 4 8 10] 
// m = 5, arr2[] = [2 3 9]

// Output: 
// arr1[] = [1 2 3 4]
// arr2[] = [8 9 10]

#include <bits/stdc++.h>
using namespace std;

//brute force by using a third array and 2 pointers
//tc 0(n+m)
//sc 0(n+m)
void merge(long long arr1[], long long arr2[], int n, int m) {
    long long arr3[n+m];
    int left=0;
    int right=0;
    int index=0;
    while(left<n&&right<m){
        if(arr1[left]<=arr2[right]){
            arr3[index++]=arr1[left++];
        }else{
            arr3[index++]=arr2[right++];
        }
    }
    while(left<n){
        arr3[index++]=arr1[left++];
    }
    while(right<m){
        arr3[index++]=arr2[right++];
    }
    for(int i=0;i<n+m;i++){
        if(i<n){
            arr1[i]=arr3[i];
        }else{
            arr2[i-n]=arr3[i];
        }
    }
}


//better method 2 pointer approach without extra space
//start comparing from the last element of array 1 and first element of array 2 and if element of array 2 is smaller then swap them and move to next element in both and when this stops happening just sort the array
//tc 0(nlogn)
//sc 0(1)
void merge2(long long arr1[], long long arr2[], int n, int m) {
    int left=n-1;
    int right=0;
    while(left>=0&&right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }else{
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}


//by gap method like shell sort
//the initial gap would be n+m/2 ceil and then we will compare elements at that index and replace if left is greater than right and then divide the gap by 2 untill it is one
//tc 0(nlogn)
//sc 0(1)
// void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
//     if (arr1[ind1] > arr2[ind2]) {
//         swap(arr1[ind1], arr2[ind2]);
//     }
// }

void swapIfGreater(long long arr1[],long long arr2[],int ind1,int ind2){
    if(arr1[ind1]>arr2[ind2]){
        swap(arr1[ind1],arr2[ind2]);
    }
}

void mergeGap(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}


int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    mergeGap(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
