//first leetcode medium i did on my own
class Solution {
public:
    string arr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(vector<string>& ans,int n,string digits,string output,int index){
        if(index==n){
            ans.push_back(output);
            return;
        }
        int i=digits[index]-'0';
        for(int j=0;j<arr[i].length();j++){
            solve(ans,n,digits,output+arr[i][j],index+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.length();
        string output="";
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        solve(ans,n,digits,output,0);
        return ans;
    }
};