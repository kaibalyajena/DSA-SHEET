#include <algorithm>
#include <iostream>
using namespace std;

//main agenda is to use minimum no of comparisons
 
struct Pair{
    int min;
    int max;
};
 
//using sorting
//first sort the array in ascending order. Once the array is sorted, the first element of the array will be the minimum element and the last element of the array will be the maximum element.
//tc 0(nlogn)
//sc 0(1)
//number of comparisons is equal to the comparisons made during sorting
Pair getMinMax(int arr[],int n){
    Pair ans;
    sort(arr,arr+n);
    ans.min=arr[0];
    ans.max=arr[n-1];
    return ans;
}


//using linear search
//Initialize values of min and max as minimum and maximum of the first two elements respectively. Starting from 3rd, compare each element with max and min, and change max and min accordingly
//tc 0(n)
//sc 0(1)
//the total number of comparisons is 1 + 2(n-2) in the worst case and 1 + n – 2 in the best case. 
//In the above implementation, the worst case occurs when elements are sorted in descending order and the best case occurs when elements are sorted in ascending order.
Pair getMinMaxLin(int arr[], int n)
{
    struct Pair ans;
    if(n==1){
        ans.max=arr[0];
        ans.min=arr[0];
        return ans;
    }
    if(arr[0]>arr[1]){
        ans.max=arr[0];
        ans.min=arr[1];
    }else{
        ans.max=arr[1];
        ans.min=arr[0];
    }
    for(int i=2;i<n;i++){
        if(arr[i]>ans.max){
            ans.max=arr[i];
        }else if(arr[i]<ans.min){
            ans.min=arr[i];
        }
    }
    return ans;
}


//using tournament method (divide and conquer)
//Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.
//tc 0(n)
//sc 0(logn)
// 3n/2 -2 comparisons if n is a power of 2. And it does more than 3n/2 -2 comparisons if n is not a power of 2.
struct Pair getMinMaxDiv(int arr[], int low, int high)
{
    Pair ans,ans_left,ans_right;
    if(low==high){
        ans.max=arr[low];
        ans.min=arr[low];
        return ans;
    }
    if(high==low+1){
        if(arr[high]>=arr[low]){
            ans.max=arr[high];
            ans.min=arr[low];
        }else{
            ans.max=arr[low];
            ans.min=arr[high];
        }
        return ans;
    }
    int mid=(low+high)/2;
    ans_left=getMinMaxDiv(arr,low,mid);
    ans_right=getMinMaxDiv(arr,mid+1,high);
    if(ans_left.max>ans_right.max){
        ans.max=ans_left.max;
    }else{
        ans.max=ans_right.max;
    }
    if(ans_left.min<ans_right.min){
        ans.min=ans_left.min;
    }else{
        ans.min=ans_right.min;
    }
    return ans;
}

//by comparing in pairs
//If n is odd then initialize min and max as the first element. 
//If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
//For the rest of the elements, pick them in pairs and compare their 
//maximum and minimum with max and min respectively. 
//tc 0(n)
//sc 0(1)
// no of comparisons If n is odd: 3*(n-1)/2, if n is even: 3n/2 -2
struct Pair getMinMaxPairs(int arr[], int n)
{
    Pair ans;
    int i;
    if(n%2==0){
        if(arr[0]>arr[1]){
            ans.max=arr[0];
            ans.min=arr[1];
        }else{
            ans.min=arr[0];
            ans.max=arr[1];
        }
        i=2;
    }else{
        ans.max=arr[0];
        ans.min=arr[0];
        i=1;
    }
    while(i<n-1){
        if(arr[i]>arr[i+1]){
            if(arr[i]>ans.max){
                ans.max=arr[i];
            }
            if(arr[i+1]<ans.min){
                ans.min=arr[i+1];
            }
        }else{
            if(arr[i+1]>ans.max){
                ans.max=arr[i+1];
            }
            if(arr[i]<ans.min){
                ans.min=arr[i];
            }
        }
        i+=2;
    }
    return ans;
}

int main()
{
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    Pair minmax = getMinMaxPairs(arr, arr_size);
    //Pair minmax = getMinMaxDiv(arr,0, arr_size-1);
    cout << "Minimum element is " << minmax.min << endl;
    cout << "Maximum element is " << minmax.max << endl;
    return 0;
}