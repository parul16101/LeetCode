//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>> &vis, int row, int col)
    {
        vis[i][j] = 1;
        
        for(int x=-1;x<=1;x++)
        {
            for(int y=-1;y<=1;y++)
            {
                int nrow = i+x;
                int ncol = j+y;
                
                if(nrow>=0 && nrow<row && ncol>=0 && ncol<col && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0)
                    dfs(nrow,ncol,grid,vis,row,col);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
       int row = grid.size(); int col = grid[0].size();
       vector<vector<int>> vis(row, vector<int>(col,0));
       int cnt = 0;
       
       for(int i=0;i<row;i++)
       {
           for(int j=0;j<col;j++)
           {
               if(vis[i][j]==0 && (grid[i][j]=='1'))
                {
                    cnt+=1;
                    dfs(i,j,grid,vis,row,col);
                }
           }
       }
       return cnt;
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