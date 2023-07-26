#include<iostream>
using namespace std;

//memoization     tc-0(n)     sc-0(n)+0(n) recursion stack and dp array.
int fib(int n,vector<int>& dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}

//tabulation

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fib(n,dp)<<endl;
    return 0;
}