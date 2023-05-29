//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>> &vis)
    {
        vis[i][j] = 1;
        int r = grid.size(), c = grid[0].size();
         
        for(int u=-1;u<=1;u++)
        {
            for(int v=-1;v<=1;v++)
            {
                int nrow = i+u;
                int ncol = j+v;
                
                if(0<=nrow && nrow<r && 0<=ncol && ncol<c && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1')
                    dfs(grid,nrow,ncol,vis);
            }
        }
            
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> vis(r, vector<int>(c,0));
        int count = 0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if((vis[i][j]==0) && (grid[i][j]=='1'))
                {
                    count += 1;
                    dfs(grid,i,j,vis);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends