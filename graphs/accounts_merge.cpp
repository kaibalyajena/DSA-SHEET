//watch strivers video for explanation

class DisjointSet{
    public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int x){
        parent.resize(x);
        size.resize(x,1);
        for(int i=0;i<x;i++){
            parent[i]=i;
        }
    }
    int findUParent(int u){
        if(parent[u]==u){
            return u;
        }else{
            return parent[u]=findUParent(parent[u]);
        }
    }
    void unionBySize(int u,int v){
        int pu=findUParent(u);
        int pv=findUParent(v);
        if(pu==pv){
            return;
        }
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pv]++;
        }else{
            parent[pu]=pv;
            size[pu]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> mp;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }else{
                    ds.unionBySize(mp[mail],i);
                }
            }
        }
        vector<string> merged_mails[n];
        for(auto it:mp){
            string mail=it.first;
            int index=ds.findUParent(it.second);
            merged_mails[index].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merged_mails[i].size()==0){
                continue;
            }
            sort(merged_mails[i].begin(),merged_mails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merged_mails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};