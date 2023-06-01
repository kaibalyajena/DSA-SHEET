#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

//by sorting
//sort and return the k-1 element for smallest and n-k-1 element for the largest
//tc 0(nlogn)
int kthSmallest(int arr[],int n,int k){
    sort(arr,arr+n);
    return arr[k-1];
}


//by using min heap (for smallest) and max heap (for largest)
//implement heap using priority queue
//put all the elements of the array in the priority queue and then pop the top of the min heap k-1 times and then print the top element (everytime we pop an element heapify is done and the smallest element comes at the top)
//tc 0(n+klogn)
int kthSmallestHeap(int arr[],int n,int k){
    int ans;
    //to implement min heap we need to add greater<int> because by default it makes a max heap.(max element at top)
    priority_queue<int,vector<int>,greater<int> > p; 
    for(int i=0;i<n;i++){
        p.push(arr[i]);
    }
    int i=1;
    while(p.empty()==false){
        if(i==k){
            ans=p.top();
            break;
        }
        p.pop();
        i++;
    }
    return ans;
}


//https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array-expected-linear-time/
//2 more approaches here (using quicksort and using map)

//by using partition approach
//tc 0(n) worst case
//https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array-worst-case-linear-time/
int findMedian(int arr[], int n)
{
    sort(arr, arr+n);  // Sort the array
    return arr[n/2];   // Return middle element
}
  
// Returns k'th smallest element in arr[l..r] in worst case
// linear time. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1; // Number of elements in arr[l..r]
  
        // Divide arr[] in groups of size 5, calculate median
        // of every group and store it in median[] array.
        int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups;
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n) //For last group with less than 5 elements
        {
            median[i] = findMedian(arr+l+i*5, n%5); 
            i++;
        }    
  
        // Find median of all medians using recursive call.
        // If median[] has only one element, then no need
        // of recursive call
        int medOfMed = (i == 1)? median[i-1]:
                                 kthSmallest(median, 0, i-1, i/2);
  
        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = partition(arr, l, r, medOfMed);
  
        // If position is same as k
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)  // If position is more, recur for left
            return kthSmallest(arr, l, pos-1, k);
  
        // Else recur for right subarray
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
  
    // If k is more than number of elements in array
    return INT_MAX;
}
  
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
// It searches for x in arr[l..r], and partitions the array 
// around x.
int partition(int arr[], int l, int r, int x)
{
    // Search for x in arr[l..r] and move it to end
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);
  
    // Standard partition algorithm
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int main(){
    int arr[]={3,6,4,2};
    int n=4;
    int k=2;
    cout<<kthSmallestHeap(arr,n,k)<<endl;;
}