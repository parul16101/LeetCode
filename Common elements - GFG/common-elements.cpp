//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public: 
        
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            unordered_set<int> s1;
            unordered_set<int> s2;
            unordered_set<int> s3;
            
            for(int i=0;i<n1;i++)
                s1.insert(A[i]);
            for(int i=0;i<n2;i++)
                s2.insert(B[i]);
            for(int i=0;i<n3;i++)
                s3.insert(C[i]);
                
            vector<int> ans;
            
            for(int i=0;i<n1;i++)
            {
                if(s1.find(A[i])!=s1.end() && s2.find(A[i])!=s2.end() && s3.find(A[i])!=s3.end())
                {
                    ans.push_back(A[i]);
                    s1.erase(A[i]);
                }
            }
            return ans;
            
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends