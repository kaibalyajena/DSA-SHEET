#include<iostream>
using namespace std;

int digSum(int n){
    if(n==0){
        return 1;
    }
    return (n%10)*digSum(n/10);
}

int main(){
    int n=1455;
    cout<<digSum(n)<<endl;
    return 0;
}