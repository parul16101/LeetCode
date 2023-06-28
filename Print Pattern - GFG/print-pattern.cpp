//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void printpattern(int N, int x, bool &f, vector<int> &ans)
    {
        if(x==N)
        {
            if(f==false)
            {
                ans.push_back(x);
                //f = true;
                printpattern(N,x-5,f,ans);
            }
            else
                {
                    ans.push_back(x);
                    return;
                }
        }
        
        else if(x>0)
        {
            ans.push_back(x);
            
            if(f)
                printpattern(N,x+5,f,ans);
            else 
                printpattern(N,x-5,f,ans);
                
        }
        else
        {
            ans.push_back(x);
            f = true;
            printpattern(N,x+5,f,ans);
        }
            
    }
            
        
    vector<int> pattern(int N){
        int x = N;
        vector<int> ans;
        bool f = false;
        printpattern(N,x,f,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends