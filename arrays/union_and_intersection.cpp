#include <bits/stdc++.h>
using namespace std;
 
//by merging
// 1) Use two index variables i and j, initial values i = 0, j = 0 
// 2) If arr1[i] is smaller than arr2[j] then print arr1[i] and increment i. 
// 3) If arr1[i] is greater than arr2[j] then print arr2[j] and increment j. 
// 4) If both are same then print any of them and increment both i and j. 
// 5) Print remaining elements of the larger array
//tc 0(m+n)
//sc 0(1)
//this code does not handle duplicates
void printUnion(int arr1[], int arr2[], int m, int n)
{
    int i=0,j=0;
    while(i<m&&j<n){
        if(arr1[i]<arr2[j]){
            cout<<arr1[i++]<<" ";
        }else if(arr2[j]<arr1[i]){
            cout<<arr2[j++]<<" ";
        }else{
            cout<<arr2[j++]<<" ";
            i++;
        }
    }
    while(i<m){
        cout<<arr1[i++]<<" ";
    }
    while(j<n){
        cout<<arr2[j++]<<" ";
    }
}


//using another array
//make an array of size max element in both arrays + 1 intialize all all zeros
//print the first element in increment its count in the new array
//traverse the first array and print elements after checking it is not equal to the previous element and increment its value in the new array
//then traverse the second array and print elements which are 0 in the new array and then increment them
//tc 0(l1+l2)
//sc 0(n)
void UnionArray(int arr1[], int arr2[], int l1,int l2)
{
    int m=arr1[l1-1];
    int n=arr2[l2-1];
    int ans=0;
    if(m>n){
        ans=m;
    }else{
        ans=n;
    }
    int table[ans+1];
    memset(table,0,sizeof(table));
    cout<<arr1[0]<<" ";
    ++table[arr1[0]];
    for(int i=1;i<l1;i++){
        if(arr1[i]!=arr1[i-1]){
            cout<<arr1[i]<<" ";
            ++table[arr1[i]];
        }
    }
    for(int i=0;i<l2;i++){
        if(table[arr2[i]]==0){
            cout<<arr2[i]<<" ";
            ++table[arr2[i]];
        }
    }
}


//by using set
//tc 0(m+n)
//sc 0(nlogn+mlogm)  adding an element to a set takes logn time
void UnionArraySet(int arr1[], int arr2[], int n, int m)
{
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        s.insert(arr2[i]);
    }
    for(auto it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
}


//by using map
//tc 0(m+n)
//sc 0(n+m)
void UnionArrayMap(int arr1[], int arr2[], int m, int n){
    map<int,int> mp;
    for(int i=0;i<m;i++){
        if(mp.find(arr1[i])==mp.end()){
            mp[arr1[i]]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(mp.find(arr2[i])==mp.end()){
            mp[arr2[i]]=1;
        }
    }
    for(auto x:mp){
        cout<<x.first<<" ";
    }
}


//by merging with duplicate handling
void next_distinct(const vector<int> &arr, int &x){
    do{
        ++x;
    } while (x < arr.size() && arr[x - 1] == arr[x]);
}
void printUnion(vector<int> arr1, vector<int> arr2)
{
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j]){
            cout << arr1[i] << " ";
            next_distinct(arr1, i); 
        }
        else if (arr1[i] > arr2[j]){
            cout << arr2[j] << " ";
            next_distinct(arr2, j); 
        }
        else{
            cout << arr1[i] << " ";
            next_distinct(arr1, i); 
            next_distinct(arr2, j);
        }
    }
    while (i < arr1.size())
    {
        cout << arr1[i] << " ";
        next_distinct(arr1, i); 
    }
    while (j < arr2.size())
    {
        cout << arr2[j] << " ";
        next_distinct(arr2, j);
    }
}



int main()
{
    int arr1[] = { 1, 2,2,2,2,2, 4, 5, 6,6,6 };
    int arr2[] = { 2, 3, 5, 7 };
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    UnionArrayMap(arr1, arr2, m, n);
    return 0;
}