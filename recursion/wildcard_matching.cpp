class Solution {
public:
    bool isMatchUtil(string &s,int si,string &p,int pi){
        if(si==s.length()&&pi==p.length()){
            return true;
        }
        if(si==s.length()){
            while(pi!=p.length()){
                if(p[pi]!='*'){
                    return false;
                }
                pi++;
            }
            return true;
        }
        if(s[si]==p[pi] || p[pi]=='?'){
            return isMatchUtil(s,si+1,p,pi+1);
        }
        if(p[pi]=='*'){
            bool caseA=isMatchUtil(s,si,p,pi+1);
            bool caseB=isMatchUtil(s,si+1,p,pi);
            return caseA || caseB;
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int si=0;
        int pi=0;
        return isMatchUtil(s,si,p,pi);
    }
};