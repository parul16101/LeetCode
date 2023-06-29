//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    void fun(vector<int> arr, int level, vector<int> temp, vector<vector<int>> &ans, int n)
    {
        if(level==n)
        {
            ans.push_back(temp);
            return;
        }
        fun(arr,level+1,temp,ans,n);
        temp.push_back(arr[level]);
        fun(arr,level+1,temp,ans,n);
    }

    
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int level = 0;
        int n = A.size();
        fun(A,level,temp,ans,n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends