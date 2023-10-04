//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
        int noOfTriangles( vector<int> v, int n)
        {
            
            sort(v.begin(), v.end());
            int ans = 0;
            
            for(int k=n-1;k>=2;k--)
            {
                int i = 0, j = k-1;
                while(i<j)
                {
                    if(v[i]+v[j]>v[k])
                    {
                        ans += (j-i);
                        j-=1;               //change second largest side
                    }
                    else
                    {
                        i+=1;
                    }
                }
            }
            return ans;
        
        }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> v(n);
	    
	    for(int i = 0; i < n; i++)
	        cin >> v[i];
	    Solution ob;
	    cout << ob.noOfTriangles(v, n) << endl;
	}
	return 0;
}
// } Driver Code Ends