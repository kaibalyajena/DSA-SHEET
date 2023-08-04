class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int satisfied_num=0;
        int curr=0;
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        for(int i=0;i<g.size();i++){
            if(curr<s.size() && s[curr]>=g[i]){
                curr++;
                satisfied_num++;
            }
        }
        return satisfied_num;
    }
};