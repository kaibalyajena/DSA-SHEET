 //on hackerrank
 long merge(vector<int>& arr,vector<int>& temp,int s,int mid,int e){
    long count=0;
    int k=s;
    int s1=s;
    int s2=mid+1;
    while(s1<=mid&&s2<=e){
        if(arr[s1]<=arr[s2]){
            temp[k++]=arr[s1++];
        }else{
            temp[k++]=arr[s2++];
            //here is the change in merge sort
            count+=mid-s1+1;
        }
    }
    while(s1<=mid){
        temp[k++]=arr[s1++];
    }
    while(s2<=e){
        temp[k++]=arr[s2++];
    }
    while(s<=e){
        arr[s]=temp[s];
        s++;
    }
    return count;
}
 
long mergeSort(vector<int>& arr,vector<int>& temp,int s,int e){
    if(s>=e){
        return 0;
    }
    long count=0;
    int mid=s+(e-s)/2;
    count += mergeSort(arr,temp,s,mid);
    count += mergeSort(arr,temp,mid+1,e);
    count += merge(arr,temp,s,mid,e);
    return count;
}

long countInversions(vector<int> arr) {
    vector<int> temp(arr.size());
    long count=0;
    count = mergeSort(arr,temp,0,arr.size()-1);
    return count;
}