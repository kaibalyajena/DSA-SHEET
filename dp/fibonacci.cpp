#include<iostream>
using namespace std;

//memoization     tc - 0(n)     sc - 0(n)+0(n) recursion stack and dp array.
// int fib(int n,vector<int>& dp){
//     if(n<=1){
//         return n;
//     }
//     if(dp[n]!=-1){
//         return dp[n];
//     }
//     return dp[n]=fib(n-1,dp)+fib(n-2,dp);
// }

//tabulation     tc - 0(n)     sc - 0(n)
// int fib(int n){
//     if(n<=1){
//         return n;
//     }
//     vector<int> dp(n+1,0);
//     dp[0]=0;// base case
//     dp[1]=1;//base case
//     for(int i=2;i<=n;i++){ // loop from the base case to the result case
//         dp[i]=dp[i-1]+dp[i-2]; // return statement
//     }
//     return dp[n];
// }

//space optimized
int fib(int n){
    if(n<=1){
        return n;
    }
    int prev2=0;// base case
    int previ=1;//base case
    for(int i=2;i<=n;i++){ // loop from the base case to the result case
        prev2=previ;
        previ=i;
    }
    return previ;
}


int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fib(n)<<endl;
    return 0;
}