//it is a type of topological sorting using bfs

//first we create an indegree array of all vertices
//the vertices with indegree 0 will come first in the topological sort so add them initially into the queue
//while traversing through the queue pop the nodes and reduce the indegree of adjacent of nodes by 1 and if any one becomes zero them push them into the queue
class Solution
{
	public:

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    vector<int> topoSort;
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        for(auto adjacent:adj[i]){
	            indegree[adjacent]++;
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topoSort.push_back(node);
	        for(auto adjacent:adj[node]){
	            indegree[adjacent]--;
	            if(indegree[adjacent]==0){
	                q.push(adjacent);
	            }
	        }
	    }
	    return topoSort;
	}
};