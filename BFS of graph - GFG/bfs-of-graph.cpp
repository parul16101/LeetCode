//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        //assume index start from 0
        queue<int> q;
        q.push(0);              //push 0 as start node is 0
        
        int vis[V]= {0};
        vis[0] = 1;
        
        //to store ans
        vector<int> bfs;
        
        while(!q.empty())
        {
            int b = q.front();
            q.pop();
            bfs.push_back(b);
            
            for(auto i:adj[b])    //adj[b] is vector which has neighbours of b
            {
                if(vis[i]==0)
                    {
                        q.push(i);
                        vis[i] = 1;
                    }
            }
            
        }
        return bfs;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends