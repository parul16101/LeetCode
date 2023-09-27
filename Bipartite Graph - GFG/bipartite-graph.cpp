//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bipartite(int i, vector<int> &color, int c, vector<int> &vis,vector<int> adj[])
    {
        vis[i] = 1;
        color[i] = c;
        c = c^1;
        
        for(auto j:adj[i])
        {
            if(vis[j]==0)
            {
                if(bipartite(j,color,c,vis,adj)==false)
	                return false;
            }
            else if(color[i]==color[j])
                return false;
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	   
	   vector<int> vis(V,0);
	   vector<int> color(V,-1);
	   int c = 0;
	   
	   for(int i=0;i<V;i++)
	   {
	       if(vis[i]==0)
	       {
	           if(bipartite(i,color,c,vis,adj)==false)
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