#include<bits/stdc++.h>
using namespace std;

bool palin(int n,int len){
    if(len==1){
        return true;
    }
    bool same=false;
    if((n%10)==(n/pow(10,len-1))){
        same=true;
    }
    int newnum=pow(10,len-2);
    return same&&palin((n/10)%(newnum),len-2);
}

 int main(){
    int n=145541;
    int len=4;
    cout<<palin(n,len)<<endl;
    return 0;
}