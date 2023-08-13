//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> m;
        int len = 0;
        int ans = INT_MIN;
        int pre_sum = 0;
        
        for(int i=0;i<n;i++)
        {
            pre_sum += A[i];
            
            if(pre_sum==0)
            {
                len = i+1;
                ans = max(ans,len);
            }
            
            if(m.find(pre_sum)==m.end())
                m[pre_sum] = i;
            else
                {
                    len = i-m[pre_sum];
                    ans = max(ans,len);
                }
        }
        if(ans==INT_MIN)    
            return 0;
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends