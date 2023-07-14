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
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> vis(row,vector<int> (col,0));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 || (i==row-1) || j==0 || (j==col-1))
                    {
                        if(grid[i][j]==1)
                        {
                            q.push({i,j});
                            vis[i][j] = 1;
                        }
                    }
            }
        }
        
        int x[4] = {-1,0,+1,0};
        int y[4] = {0,+1,0,-1};
        
        while(!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int nrow = a+x[k];
                int ncol = b+y[k];
                
                if(isValid(nrow,ncol,row,col) && grid[nrow][ncol]==1 && vis[nrow][ncol]==0)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
                
            }
        }
        
        int count = 0;
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                    count+=1;
            }
        }
        return count;
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