//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    bool isValid(int nr, int nc, int r, int c)
    {
        return 0<=nr && nr<r && 0<=nc && nc<c;
    }
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int row = grid.size(), col = grid[0].size();
	    
	    vector<vector<int>> vis(row, vector<int>(col,0));
	    vector<vector<int>> ans(row, vector<int>(col,0));
	    
	    queue<pair<pair<int,int>,int>> q;
	    
	    for(int i=0;i<row;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({{i,j},0});
	            }
	        }
	    }
	    
	    int a[4] = {-1,0,+1,0};
	    int b[4] = {0,+1,0,-1};
	    
	    while(!q.empty())
	    {
	        int x = q.front().first.first;
	        int y = q.front().first.second;
	        int t = q.front().second;
	        q.pop();
	        
	        for(int i=0;i<4;i++)
	        {
	            int nrow = x+a[i];
	            int ncol = y+b[i];
	            
	            if(isValid(nrow,ncol,row,col) && grid[nrow][ncol]==0 && vis[nrow][ncol]==0)
	            {
	                vis[nrow][ncol] = 1;
	                q.push({{nrow,ncol},t+1});
	                ans[nrow][ncol] = t+1;
	            }
	        }
	        
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends