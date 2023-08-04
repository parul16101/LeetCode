//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool isValid(int nrow, int ncol, int a, int b)
    {
        return (0<=nrow && nrow<a && 0<=ncol && ncol<b);
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>> &vis)
    {
        vis[i][j] = 1;
        int row = grid.size();
        int col = grid[0].size();
        
        for(int a=-1;a<=1;a++)
        {
            for(int b=-1;b<=1;b++)
            {
                int nrow = i+a;
                int ncol = j+b;
                
                if(isValid(nrow,ncol,row,col) && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0)
                    dfs(nrow,ncol,grid,vis);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> vis(row, vector<int>(col,0));
        int count = 0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1' &&vis[i][j]==0)
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