class Solution {
public:
    void addStringsUtil(string &num1,string &num2,int index1,int index2,int carry,string &ans){
        if(index1<0&&index2<0){
            if(carry!=0){
                ans.push_back(carry+'0');
            }
            return;
        }
        int n1=((index1>=0 ? num1[index1] : '0')-'0');
        int n2=((index2>=0 ? num2[index2] : '0')-'0');
        int total_sum=n1+n2+carry;
        int digit=total_sum%10;
        carry=total_sum/10;
        ans.push_back(digit+'0');
        addStringsUtil(num1,num2,index1-1,index2-1,carry,ans);
    }

    string addStrings(string num1, string num2) {
        string ans="";
        int carry=0;
        addStringsUtil(num1,num2,num1.length()-1,num2.length()-1,carry,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};