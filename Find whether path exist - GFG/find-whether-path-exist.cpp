//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool isvalid(int nrow, int ncol, int row, int col)
    {
        return (nrow>=0 && nrow<row && ncol>=0 && ncol<col);
    }
    
    bool dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &vis)
    {
         int row = grid.size(), col = grid[0].size();
         vis[r][c] = 1;
         
         //cout<<r<<" "<<c<<" "<<grid[r][c]<<endl;
         if(grid[r][c]==0)
            return false;
         
         if(grid[r][c]==2)
            return true;
            
        int x[4] = {-1,0,1,0};
        int y[4] = {0,1,0,-1};
        
         for(int i=0;i<4;i++)
         {
                 int nrow = r+x[i];
                 int ncol = c+y[i];
                 
                 
                 if(isvalid(nrow,ncol,row,col) && vis[nrow][ncol]==0)
                    {
                        if(dfs(nrow,ncol,grid,vis))
                            return true;
                    }
         }
         
         return false;
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        int r=0, c=0;
    
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                     r = i;
                     c = j;
                }}}
                
        return dfs(r,c,grid,vis);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends