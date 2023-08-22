//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	bool isValid(int nrow, int ncol, int row, int col)
    {
        return (nrow>=0 && nrow<row && ncol>=0 && ncol<col);
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int row = N, col = N;
	    vector<vector<int>> vis(N, vector<int> (N,0));
	    
	    queue<pair<pair<int,int>,int>> q;
	    int p1 = KnightPos[0]-1; int p2 = KnightPos[1]-1;
	    int t1 = TargetPos[0]-1; int t2 = TargetPos[1]-1;
	    
	    q.push({{p1,p2},0});
	    
	    vis[p1][p2] = 1;
	    
	    int v1[] = {-1, -2, -2, -1, 1, 2,  2,  1};
	    int v2[] = {-2, -1,  1,  2, 2, 1, -1, -2};
	    
	    while(!q.empty())
	    {
	        int a = q.front().first.first;
	        int b = q.front().first.second;
	        int t = q.front().second;
	        q.pop();
	        
	        if(a==t1 && b==t2)
	            return t;
	        
	        for(int i=0;i<8;i++)
	        {
	            int nrow = a+v1[i];
	            int ncol = b+v2[i];
	            
	            if(isValid(nrow,ncol,row,col) && vis[nrow][ncol]==0)
	            {
	                q.push({{nrow,ncol},t+1});
	                vis[nrow][ncol] = 1;
	                
	            }
	        }
	    }
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends