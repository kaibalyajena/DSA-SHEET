// Given an array of integers where each element represents the max number of steps that can be made forward from that element. 
//Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). 
//If an element is 0, then we cannot move through that element. If we can't reach the end, return -1.
#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
    return (x > y) ? x : y;
}


//by using recursion
//tc 0(N^n);
//sc 0(n)
int minJumpsRec(int arr[], int n){
    //base case
    //source and destination are the same
    if(n==1){
        return 0;
    }
    //min no of jumps
    int res=INT_MAX;
    //loop from second last to the first element of the array
    for(int i=n-2;i>=0;i--){
        //check if we can reach the last postion from the current position(current position + no of steps we can take from the current position)
        if(i+arr[i]>=n-1){
            //calculate the min no jumps required to reach last postion from current position+1
            int sub_res=minJumpsRec(arr,i+1);
            //if possible to reach the compute the minimum
            if(sub_res!=INT_MAX){
                res=min(res,sub_res+1);
            }
        }
    }
    return res;
}



//by using dynamic programming
// Create jumps[] array from left to right such that jumps[i] indicate the minimum number of jumps needed to reach arr[i] from arr[0].
// To fill the jumps array run a nested loop inner loop counter is j and the outer loop count is i.
// Outer loop from 1 to n-1 and inner loop from 0 to i.
// if i is reachable from j
// If i is less than j + arr[j] then set jumps[i] to minimum of jumps[i] and jumps[j] + 1. initially set jump[i] to INT MAX
// Return jumps[n-1].
//tc 0(N2);
//sc 0(n)
int minJumpsDP(int arr[], int n){
    if(arr[0]==0||n==0){
        return -1;
    }
    int jumps[n];
    memset(jumps,1000000,sizeof(jumps));
    jumps[0]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(j+arr[j]>=i){
                jumps[i]=min(jumps[i],jumps[j]+1);
            }
        }
    }
    return jumps[n-1];
}



//by greedy algorithm
//tc 0(N);
//sc 0(1)
int minJumps(int arr[], int n){
    if(n<=1){
        return 0;
    }
    if(arr[0]==0){
        return -1;
    }
    int maxReach=arr[0];
    int steps=arr[0];
    int jumps=1;
    for(int i=1;i<n;i++){
        if(i==n-1){
            return jumps;
        }
        maxReach=max(maxReach,i+arr[i]);
        steps--;
        if(steps==0){
            jumps++;
            if(i>=maxReach){
                return -1;
            }
            steps=maxReach-i;
        }
    }
    return -1;
    // // The number of jumps needed to
    // // reach the starting index is 0
    // if (n <= 1)
    //     return 0;

    // // Return -1 if not possible to jump
    // if (arr[0] == 0)
    //     return -1;

    // // initialization
    // // stores all time the maximal
    // // reachable index in the array.
    // int maxReach = arr[0];

    // // stores the number of steps
    // // we can still take
    // int step = arr[0];

    // // stores the number of jumps
    // // necessary to reach that maximal
    // // reachable position.
    // int jump = 1;

    // // Start traversing array
    // int i = 1;
    // for (i = 1; i < n; i++) {
    //     // Check if we have reached the end of the array
    //     if (i == n - 1)
    //         return jump;

    //     // updating maxReach
    //     maxReach = max(maxReach, i + arr[i]);

    //     // we use a step to get to the current index
    //     step--;

    //     // If no further steps left
    //     if (step == 0) {
    //         // we must have used a jump
    //         jump++;

    //         // Check if the current index/position or lesser index
    //         // is the maximum reach point from the previous indexes
    //         if (i >= maxReach)
    //             return -1;

    //         // re-initialize the steps to the amount
    //         // of steps to reach maxReach from position i.
    //         step = maxReach - i;
    //     }
    // }
    // return -1;
}


int main(){
    int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    int size = sizeof(arr) / sizeof(int);
    cout << "Minimum number of jumps to reach end is "<<minJumpsDP(arr, size);
    return 0;
}