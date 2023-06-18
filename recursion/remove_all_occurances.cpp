class Solution {
public:
    void removed(string &s,string part){
        int find=s.find(part);
        if(find!=string::npos){
            string left=s.substr(0,find);
            string right=s.substr(find+part.length(),s.length());
            s=left+right;
            removed(s,part);
        }else{
            return;
        }
    }


    string removeOccurrences(string s, string part) {
        removed(s,part);
        return s;
    }
};