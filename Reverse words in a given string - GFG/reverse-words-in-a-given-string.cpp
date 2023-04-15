//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    
    void rev(string &S, int f, int e)
    {
        while(f<e)
        {
            swap(S[f],S[e]);
            f+=1;
            e-=1;
        }
    }
    
    string reverseWords(string S) 
    { 
        int s = 0, e = 0, i = 0, n = S.size();
        
        while(i<n)
        {
            if(S[i]=='.')
                {
                    rev(S,s,e-1);
                    s = i+1;
                }
            e+=1;
            i+=1;
        }
        e-=1;
        rev(S,s,e);
        rev(S,0,n-1);
        return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends