//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
       int n = s1.size();
       int m = s2.size();
       
       if(n!=m)
        return 0;
        
       s2 = s2+s2;
       
       int j=0;
       while(j<=n)
       {
           if(s2.substr(j,n)==s1)
                return 1;
            j+=1;
       }
       return 0;
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends