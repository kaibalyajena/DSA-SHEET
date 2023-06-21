 #include<iostream>
 using namespace std;

 void permutations(string &str,int i){
    if(i==str.length()){
        cout<<str<<endl;
        return;
    }
    for(int j=i;j<str.length();j++){
        swap(str[i],str[j]);
        permutations(str,i+1);
        //the line below is the backtracking part
        //as we have taken the string by reference so when one recursive call is over 
        //and the other recusive call of the other branch is going to execute then the
        // original string has been changed so to bring back the original string we do the same swap operation which changed the string
        swap(str[i],str[j]);
    }
 }

 int main(){
    string str="abc";
    permutations(str,0);
    return 0;
 }