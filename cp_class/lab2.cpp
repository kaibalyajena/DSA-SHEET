#include<bits/stdc++.h>
using namespace std;

int computeSum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){
    // int n=6;
    // int m=4;
    // int arr1[]={4,1,2,1,1,2};
    // int arr2[]={3,6,3,3};
    // int n=4;
    // int m=4;
    // int arr1[]={5,7,4,6};
    // int arr2[]={1,2,3,8};
    // int n=5;
    // int m=5;
    // int arr1[]={-5,10,15,20,-25};
    // int arr2[]={30,-35,40,-45,50};
    vector<int> arr1;
    vector<int> arr2;
    int x;
    while(cin>>x){
        if(x==0){
            break;
        }
        arr1.push_back(x);
    }
    // string st;
    // while(cin>>st){
    //     if(st=="\n"){
    //         break;
    //     }
    //     int y=stoi(st);
    //     arr2.push_back(y);
    // }
    for(auto x:arr1){
        cout<<x<<" ";
    }
    cout<<endl;
    // for(auto x:arr2){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // vector<pair<int,int> > ans;
    // int sarr1=computeSum(arr1,n);
    // int sarr2=computeSum(arr2,m);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(sarr1-arr1[i]+arr2[j]==sarr2-arr2[j]+arr1[i]){
    //             ans.push_back(make_pair(arr1[i],arr2[j]));
    //         }
    //     }
    // }
    // if(ans.size()==0){
    //     cout<<"Not Found"<<endl;
    // }else{
    //     cout<<ans[ans.size()-1].first<<" "<<ans[ans.size()-1].second<<endl;
    // }
    // return 0;
}