//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int i,  vector<int> adjl[], vector<int> &vis)
    {
        vis[i] = 1;
        
        for(auto j:adjl[i])
        {
            if(vis[j]!=1)
            {
                dfs(j,adjl,vis);
            }
            
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjl[V];
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]!=0 && i!=j)
                {
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        
        //int vis[V] = {0};
        vector<int> vis(V,0);
        int c = 0;
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
                {   
                    dfs(i,adjl,vis);
                    c+=1;
                }
        }
        return c;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends