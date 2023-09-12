#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<float,float> > arr(n);
    for(int i=0;i<n;i++){
        float x,y;
        cin>>x>>y;
        arr[i]=make_pair(x,y);
    }
    int max_num=INT_MIN;
    int max_pos=INT_MIN;
    int num=0;
    int pos=0;
    map<int,int> mp;
    for(int i=0;i<n-1;i++){
        if(arr[i].first<=arr[i+1].first && arr[i].second<=arr[i+1].second){
            num++;
            max_num=max(max_num,num);
        }else{
            mp[num]=pos;
            num=0;
            pos=i+1;
        }
    }
    cout<<max_num+1<<endl;
    cout<<mp[max_num]+1<<endl;
    return 0;
}