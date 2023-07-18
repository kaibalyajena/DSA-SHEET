//works only for directed acyclic graph
class Solution
{
	public:
	void dfs(int s,vector<int>& visited,stack<int> &st,vector<int> adj[]){
	    visited[s]=1;
	    for(auto adjacent:adj[s]){
	        if(!visited[adjacent]){
	            dfs(adjacent,visited,st,adj);
	        }
	    }
        //when dfs is over push the s into stack and in the end just pop the stack and print the stack untill empty
	    st.push(s);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V,0);
	    vector<int> ans;
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(i,visited,st,adj);
	        }
	    }
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};