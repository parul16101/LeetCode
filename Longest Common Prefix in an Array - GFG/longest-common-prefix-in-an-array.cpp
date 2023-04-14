//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        int size = INT_MAX;
        for(int i=0;i<N;i++)
        {
            int s = arr[i].size();
            size = min(size,s);
        }
        
        string ans = "";
        char c ;
        int f=0;
        
        for(int i=0;i<size;i++)
        {
            c = arr[0][i] ;
            for(int j=0;j<N;j++)
            {
                if(arr[j][i]!=c)
                    {
                        f=1;
                        break;
                    }
                else if(j==N-1)
                {
                    ans += c;
                }
            }
            if(f==1)
                break;
        }
        if(ans=="")
            return "-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends