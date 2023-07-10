//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int s, int d, vector<vector<int>> &adj, vector<int> vis, int &c)
    {
        if(s==d)
        {
            c+=1;
            return;
        }
        
        vis[s] = 1;
        
        for(auto i:adj[s])
        {
            if(vis[i]==0)
                dfs(i,d,adj,vis,c);
        }
    }

	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	   int count = 0;
	   vector<int> vis(n,0);
	   
	   vector<vector<int>> adj(n);
	   
	   for(int i=0;i<edges.size();i++)
	   {
	       int a = edges[i][0];
	       int b = edges[i][1];
	       
	       adj[a].push_back(b);
	   }
	   
	   dfs(s,d,adj,vis,count);
	   return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends