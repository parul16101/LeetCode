//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isValid(int nrow, int ncol, int row, int col)
    {
        return (nrow>=0 && nrow<row && ncol>=0 && ncol<col);
    }
    
    void dfs(int i, int j, int iC, int nC, vector<vector<int>> &vis, vector<vector<int>> image,
    vector<vector<int>> &ans)
    {
        int row = image.size(); int col = image[0].size();
        ans[i][j] = nC;
        vis[i][j] = 1;
        
        int x[4] = {-1,0,+1,0};
        int y[4] = {0,+1,0,-1};
        for(int k=0;k<4;k++)
        {
            int nrow = i+x[k];
            int ncol = j+y[k];
            
            if(isValid(nrow,ncol,row,col) && image[nrow][ncol]==iC && vis[nrow][ncol]==0)
            {
                dfs(nrow,ncol,iC,nC,vis,image,ans);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size(); int col = image[0].size();
        vector<vector<int>> ans(row,vector<int>(col,0));
        ans = image;
        
        vector<vector<int>> vis(row,vector<int>(col,0));
        
        int iniColor = image[sr][sc];
        
        dfs(sr,sc,iniColor,newColor,vis,image,ans);
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends