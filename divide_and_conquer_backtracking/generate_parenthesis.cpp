class Solution {
public:
    void solve(vector<string>& ans, int open ,int close,int n,string& output){
        if(open==0&&close==0){
            ans.push_back(output);
            return;
        }
        //either include closing or opening bracket in each function call
        if(open>0){
            output.push_back('(');
            solve(ans,open-1,close,n,output);
            //backtrack
            output.pop_back();
        }
        //we can only add closing bracket if it's number is greater than no of closing brackets
        if(close>open){
            output.push_back(')');
            solve(ans,open,close-1,n,output);
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output="";
        int open=n;
        int close=n;
        solve(ans,open,close,n,output);
        return ans;
    }
};