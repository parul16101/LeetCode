//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool isvalid(int nrow, int ncol, int r, int c)
    {
        return (nrow>=0 && nrow<r && ncol>=0 && ncol<c);
    }
    
    void dfs(int sr, int sc,vector<vector<int>>& image,int newColor,int b,vector<vector<int>> &vis,vector<vector<int>> &ans )
    {
        vis[sr][sc] = 1;
        ans[sr][sc] = newColor;
        int r = image.size(), c = image[0].size();
        
        int u[4] = {-1,0,1,0};
        int v[4] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
                int nrow = sr+u[i]; int ncol = sc+v[i];
                
                if(isvalid(nrow,ncol,r,c) && vis[nrow][ncol]==0 && image[nrow][ncol]==b)
                        dfs(nrow,ncol,image,newColor,b,vis,ans);
                    
        }
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int b = image[sr][sc];
        int row = image.size(); int col = image[0].size();
        vector<vector<int>> vis(row,vector<int> (col,0));
        vector<vector<int>> ans = image;
        dfs(sr,sc,image,newColor,b,vis,ans);
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