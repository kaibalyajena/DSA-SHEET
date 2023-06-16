#include<iostream>
using namespace std;

int zeros(int n,int count){
    if(n==0){
        return count;
    }
    if(n%10==0){
        return zeros(n/10,count+1);
    }
    return zeros(n/10,count);
}

int zero(int n){
    if(n==0){
        return 0;
    }
    if(n%10==0){
        return 1+zero(n/10);
    }
    return zero(n/10);
}

int main(){
    int n=1045005;
    cout<<zero(n)<<endl;
    return 0;
}