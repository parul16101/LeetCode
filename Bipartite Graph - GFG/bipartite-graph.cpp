//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int i, vector<int> &vis, vector<int>adj[], int V, int c)
    {
        vis[i] = c;
        c = c^1;
        
        for(auto j:adj[i])
        {
            if(vis[j]==-1)
            {
                if(dfs(j,vis,adj,V,c)==false)
	                return false;
            }
            else if(vis[i]==vis[j])
                return false;
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis(V,-1);
	    int c = 0;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==-1)
	        {
	            if(dfs(i,vis,adj,V,c)==false)
	                return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends