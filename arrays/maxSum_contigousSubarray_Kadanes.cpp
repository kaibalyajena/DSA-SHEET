#include <bits/stdc++.h>
using namespace std;

//brute force
//calculate the sum of all the subarrays and find the maximum
//tc 0(n3)
//sc 0(1)
int maxSubarraySum(int arr[], int n) {
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            maxi=max(maxi,sum);
        }
    }
    return maxi;
}

//better approach
//calculate the sum of all the subarrays and find the maximum
//to get the sum of the current subarray we just need to add the current element to the sum of the previous subarray (eliminating the need of the third loop)
//tc 0(n2)
//sc 0(1)
int maxSubarraySum2(int arr[], int n) {
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            maxi=max(maxi,sum);
        }
    }
    return maxi;
}


//optimal approach
//kadane's algorithm
// The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
// Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.
// Thus we can solve this problem with a single loop.
//tc 0(n)
//sc 0(1)
int kadanes(int arr[], int n) {
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    // To consider the sum of the empty subarray
    //if (maxi < 0) maxi = 0;
    return maxi;
}


//to print any of the contiguous subarray with maximum sum
//Our approach is to store the starting index and the ending index of the subarray.
//subarray always starts at the particular index where the sum variable is equal to 0, and at the ending index, the sum always crosses the previous maximum sum(i.e. maxi)
//keep a track of the starting index inside the loop using a start variable.
//take two variables ansStart and ansEnd initialized with -1. And when the sum crosses the maximum sum, we will set ansStart to the start variable and ansEnd to the current index i.e. i.
void printKadanes(int arr[],int n){
    int start=0;
    int ansStart=-1,ansEnd=-1;
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(sum==0){
            start=i;
        }
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
            ansStart=start;
            ansEnd=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int maxSum = kadanes(arr, n);
    // cout << "The maximum subarray sum is: " << maxSum << endl;
    printKadanes(arr,n);
    return 0;
}