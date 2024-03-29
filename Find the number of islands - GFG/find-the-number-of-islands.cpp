//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool isValid(int nrow, int ncol, int row, int col)
    {
        return (0<=nrow && nrow<row && 0<=ncol && ncol<col);
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>> &vis)
    {
         int row = grid.size(), col = grid[0].size();
         vis[i][j] = 1;
         
         for(int u=-1;u<=1;u++)
         {
             for(int v=-1;v<=1;v++)
             {
                 int nrow = i+u;
                 int ncol = j+v;
                 
                 if(isValid(nrow,ncol,row,col) && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0)
                 {
                     dfs(nrow,ncol,grid,vis);
                 }
             }
         }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> vis(row,vector<int> (col,0));
        
        int count = 0;
        
        for(int i=0;i<row;i++)
        {
         for(int j=0;j<col;j++)
         {
             if(grid[i][j]=='1' && vis[i][j]==0)
             {
                 count+=1;
                 dfs(i,j,grid,vis);
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