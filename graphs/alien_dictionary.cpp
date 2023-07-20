// we need to create an adjacency list from the dictionary given and then do topo sort and then convert the toposort into a string
class Solution{
    public:
    vector<int> topoSort(int v,vector<int> adj[]){
        vector<int> indegree(v,0);
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<v;i++){
            for(auto adjacent:adj[i]){
                indegree[adjacent]++;
            }
        }
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto adjacent:adj[node]){
                indegree[adjacent]--;
                if(indegree[adjacent]==0){
                    q.push(adjacent);
                }
            }
        }
        return topo;
    }
    //k means no of alphabets like k=4 means a,b,c,d are involved
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.size(),s2.size());
            for(int j=0;j<len;j++){
                //whenever the alphabet of the string become diff for the first time , that must have been the reason to keep s1 before s2 in the dictionary 
                //so we got to know that s1[j] comes before s2[j] in alphabetical order (in topo sort if a->b then a comes before b)
                //so using the same concept we make s1[j]->s2[j]
                //to convert them into integer we subtract a (ascii value)   so a->0 b->1 c->3 and so on
                //and we later convert it again by adding a   0->a 1->b and so on.
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> topo=topoSort(K,adj);
        string s;
        for(auto i:topo){
            s.push_back(i+'a');
        }
        return s;
    }
};


//interviewer can ask if the dictionary given is not correct then how will you find out
//we must add code to check 2 conditions
//like if abce and abc is there then add check that abc should could come before
//and check for cyclic redundancy (just check if topo.size()!=k). if would be present if this is the order (abc,bacc,acc)