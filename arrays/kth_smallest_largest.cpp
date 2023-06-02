#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
#include<cstdlib>
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


//by randomized partition approach (like quicksort)
//expected linear time
//approach
//select a random element from the array as pivot
//partition that array around that pivot. elements smaller than the array on the left side of the pivot and vice versa. pivot element present in the correct place if the array was sorted.
//check the position of the pivot, if it is the kth element then return it.
//if pivot's index is greater than k then process the left subarray and vice versa
//tc 0(n2) worst case
//sc 0(1)
int randomPartition(int arr[],int l,int r);
int kthSmallestQuick(int arr[],int l,int r, int k){
    check if k is less that or equal to the no of elements in the array
    if(k>0&&k<=r-l+1){
        int pos=randomPartition(arr,l,r);
        if(pos-l==k-1){
            return arr[pos];
        }
        if(pos-l>k-1){
            return kthSmallestQuick(arr,l,pos-1,k);
        }
        return kthSmallestQuick(arr,pos+1,r,k-pos+l-1);
    }
    return INT_MAX;
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
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
int randomPartition(int arr[], int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return partition(arr, l, r);
}

//by using map
//approach
//store the freq of every element in a map (map stores data in a sorted manner)
//now traverse the sorted element in the map and add the frequencies to a variable
//at any point of time that variable is greater or equal to k, then return the value of the iterator of map.
//tc 0(nlogn)
//sc 0(n)
// int Kth_smallest(map<int, int> mp, int k)
// {
//     int freq=0;
//     for(auto it=mp.begin();it!=mp.end();it++){
//         freq+=it->second;
//         if(freq>=k){
//             return it->first;
//         }
//     }
//     return -1;
// }
// int main()
// {
//     int N = 5;
//     int K = 2;
//     vector<int> arr = { 12, 3, 5, 7, 19 };
//     map<int, int> mp;
//     for (int i = 0; i < N; i++) {
//         mp[arr[i]] += 1;
//     }
//     int ans = Kth_smallest(mp, K);
//     cout << "The " << K << "th smallest element is " << ans<< endl;
//     return 0;
// }




//by using median partition approach
//tc 0(n) worst case
//assumption is that all elements are distinct
// kthSmallest(arr[0..n-1], k) 
// 1) Divide arr[] into ⌈n/5⌉ groups where size of each group is 5 except possibly the last group which may have less than 5 elements. 
// 2) Sort the above created ⌈n/5⌉ groups and find median of all groups. Create an auxiliary array ‘median[]’ and store medians of all ⌈n/5⌉ groups in this median array.
// // Recursively call this method to find median of median[0..⌈n/5⌉-1] 
// 3) medOfMed = kthSmallest(median[0..⌈n/5⌉-1], ⌈n/10⌉)
// 4) Partition arr[] around medOfMed and obtain its position. 
// pos = partition(arr, n, medOfMed)
// 5) If pos == k return medOfMed 
// 6) If pos > k return kthSmallest(arr[l..pos-1], k) 
// 7) If pos < k return kthSmallest(arr[pos+1..r], k-pos+l-1)
//https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array-worst-case-linear-time/
// int findMedian(int arr[], int n)
// {
//     sort(arr, arr+n);  // Sort the array
//     return arr[n/2];   // Return middle element
// }
// int kthSmallest(int arr[], int l, int r, int k)
// {
//     if (k > 0 && k <= r - l + 1)
//     {
//         int n = r-l+1;
//         // Divide arr[] in groups of size 5, calculate median
//         // of every group and store it in median[] array.
//         int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups;
//         for (i=0; i<n/5; i++)
//             median[i] = findMedian(arr+l+i*5, 5);
//         if (i*5 < n) //For last group with less than 5 elements
//         {
//             median[i] = findMedian(arr+l+i*5, n%5); 
//             i++;
//         }    
  
//         // Find median of all medians using recursive call.
//         // If median[] has only one element, then no need
//         // of recursive call
//         int medOfMed = (i == 1)? median[i-1]:
//                                  kthSmallest(median, 0, i-1, i/2);
  
//         // Partition the array around a random element and
//         // get position of pivot element in sorted array
//         int pos = partition(arr, l, r, medOfMed);
  
//         // If position is same as k
//         if (pos-l == k-1)
//             return arr[pos];
//         if (pos-l > k-1)  // If position is more, recur for left
//             return kthSmallest(arr, l, pos-1, k);
//         return kthSmallest(arr, pos+1, r, k-pos+l-1);
//     }
//     return INT_MAX;
// }
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// It searches for x in arr[l..r], and partitions the array 
// around x.
// int partition(int arr[], int l, int r, int x)
// {
//     int i;
//     for (i=l; i<r; i++)
//         if (arr[i] == x)
//            break;
//     swap(&arr[i], &arr[r]);
//     // Standard partition algorithm
//     i = l;
//     for (int j = l; j <= r - 1; j++)
//     {
//         if (arr[j] <= x)
//         {
//             swap(&arr[i], &arr[j]);
//             i++;
//         }
//     }
//     swap(&arr[i], &arr[r]);
//     return i;
// }

int main(){
    int arr[]={3,6,4,2};
    int n=4;
    int k=2;
    cout<<kthSmallestQuick(arr,0,n-1,k)<<endl;;
}