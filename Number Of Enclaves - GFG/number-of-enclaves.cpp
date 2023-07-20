//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(int nrow, int ncol, int row, int col)
    {
        return (nrow>=0 && nrow<row && ncol>=0 && ncol<col);
    }
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q;
        int row = grid.size(); int col = grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 || (i==row-1) || j==0 || (j==col-1))
                {
                    if(grid[i][j]==1)
                    {q.push({i,j});
                    vis[i][j] = 1;}
                }
            }
        }
        
        int u[4] = {-1,0,+1,0};
        int v[4] = {0,+1,0,-1};
        
        while(!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                 int nrow = a+u[i];
                 int ncol = b+v[i];
                 
                 if(isValid(nrow,ncol,row,col) && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
                 {
                     vis[nrow][ncol] = 1;
                     q.push({nrow,ncol});
                 }
            }
        }
        int res = 0;
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                    res+=1;
            }
        }
        return res;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends