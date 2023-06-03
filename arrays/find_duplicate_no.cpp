#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

//we can also use bit manupulation

//by sorting
// Sort the input array
// Iterate through the array, comparing the current number to the previous number 
// Return the first number that is equal to its predecessor.
//tc 0(nlogn)
//sc 0(logn) used by stl sort
int findDuplicate(int arr[],int n){
    sort(arr,arr+n);
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            return arr[i];
            break;
        }
    }
    return -1;
}



//by using unordered set
//tc 0(n)
//sc 0(n)
int findDuplicateSet(int arr[],int n){
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        if(s.count(arr[i])==1){
            return arr[i];
            break;
        }
        s.insert(arr[i]);
    }
    return -1;
}


//by making a count array
//tc 0(n)
//sc 0(n)
int findDuplicateCount(int arr[],int n){
    int count[n+1];
    memset(count,0,sizeof(count));
    for(int i=0;i<n;i++){
        count[arr[i]]+=1;
    }
    for(int i=0;i<=n;i++){
        if(count[i]>1){
            return i;
        }
    }
    return -1;
}


//by negative marking
//traverse the array make arr[arr[i]] -ve and if it was already negative then it is repeated no.
//tc 0(n)
//sc 0(1)
int findDuplicateNeg(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])]<0){
            return abs(arr[i]);
        }
        arr[abs(arr[i])]=-arr[abs(arr[i])];
    }
    return -1;
}


//by using floyd cycle detection
//no array modification
//tc 0(n)
//sc 0(1)
int findDuplicateFloyd(vector<int>& nums) {
    // Find the intersection point of the two runners.
    int tortoise = nums[0];
    int hare = nums[0];
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);
    // Find the "entrance" to the cycle.
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    return hare;
}


int main(){
    int arr[]={1,2,3,4,5,5};
    int n=6;
    cout<<findDuplicateNeg(arr,n)<<endl;
    return 0;
}

