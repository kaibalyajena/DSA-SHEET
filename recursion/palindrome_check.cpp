#include <bits/stdc++.h>
using namespace std;

bool solve(string str,int l,int r){
  if(l>r){
    return true;
  }
  if(str[l]!=str[r]){
    return false;
  }
  return solve(str,l+1,r-1);
}


int main(){
  string str="racecare";
  cout<<solve(str,0,str.length()-1)<<endl;
}