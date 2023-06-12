#include<bits/stdc++.h>
using namespace std;

int reverseNum(int n,int len){
    if(len==1){
        return n;
    }
    return ((n%10)*pow(10,len-1))+reverseNum(n/10,len-1);
}

 int main(){
    int n=1455;
    int len=4;
    cout<<reverseNum(n,len)<<endl;
    return 0;
}