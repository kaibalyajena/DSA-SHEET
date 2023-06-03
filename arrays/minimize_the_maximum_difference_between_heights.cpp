#include <bits/stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;


//by sorting
//sort the array. compute the temporary ans by subtracting the last and first element. then iterate and check if any element-k beccomes the smaller than smallest element+k and any element+k becomes larger than largest element-k
//and calculate the new ans by taking minimum. 
//tc 0(nlogn)
//sc 0(1)
int getMinDiff(int arr[], int n, int k){
    sort(arr,arr+n);
    int tempMax=arr[n-1];
    int tempMin=arr[0];
    int minDiff=tempMax-tempMin;
    for(int i=1;i<n;i++){
        if(arr[i]-k<0){
            continue;
        }
        tempMax=max(arr[n-1]-k,arr[i-1]+k);
        tempMin=min(arr[0]+k,arr[i]-k);
        minDiff=min(minDiff,tempMax-tempMin);
    }
    return minDiff;
}


//by greedy algo
// increase or decrease the heights of the towers in a way that moves the towers closer to the average height.
//Initialize the minimum and maximum heights in the array to arr[0].
// Loop through the array and update the minimum and maximum heights as necessary. At the end of this step, we should have the minimum and maximum heights in the array.
// Calculate the initial difference between the maximum and minimum heights.
// Calculate the average height by taking the sum of the minimum and maximum heights and dividing it by 2.
// Loop through the array and modify the heights of the towers as follows:
// a. If the height of a tower is less than or equal to the average height, increase its height by K.
// b. If the height of a tower is greater than the average height, decrease its height by K.
// Calculate the new minimum and maximum heights in the modified array.
// Calculate the new difference between the maximum and minimum heights.
// If the new difference is greater than or equal to the initial difference, return the initial difference. Otherwise, return the new difference
//tc 0(n)
//sc 0(1)
int getMinDiffGreedy(int arr[], int n, int k){
    int max1=*max_element(arr,arr+n);
    int min1=*min_element(arr,arr+n);
    int initialDiff=max1-min1;
    int avg=(max1+min1)/2;
    for(int i=0;i<n;i++){
        if(arr[i]<=avg){
            arr[i]+=k;
        }else{
            arr[i]-=k;
        }
    }
    int max2=*max_element(arr,arr+n);
    int min2=*min_element(arr,arr+n);
    int finalDiff=max2-min2;
    if(finalDiff<initialDiff){
        return finalDiff;
    }else{
        return initialDiff;
    }
}

int main()
{
 
    int k = 6, n = 6;
    int arr[] = { 7, 4, 8, 8, 8, 9 };
    int ans = getMinDiffGreedy(arr, n, k);
    cout << ans;
}