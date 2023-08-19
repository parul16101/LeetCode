//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
         
        string ans = "";
        
        int len = S.size();
        int j = 0;
        int ind = 0;
        bool prev = false;
        int n = 0;
        
        for(int i=0;i<Q;i++)
        {
            ind = index[i];
            string source = sources[i];
            string target = targets[i];
            
            n = source.size();
            
            if(i==0)
                j=0;
            else
            {
                if(prev)
                    {
                        j = index[i-1]+sources[i-1].size();
                    }
                else
                    {
                        j = index[i-1]+1;
                    }
            }
            while(j<len && j<ind)
            {
                ans += S[j];
                j+=1;
            }
            
            if((len-ind)>=n && S.substr(ind,n)==source)
               { 
                   prev = true;
                   ans += target;  
                   if(ind+n==len)
                        return ans;
               }
            else
               { ans += S[ind];
                   prev=false;
               }
        }
        
        // len = 10
        // [4]
        // []
        
        if(prev)
            ind+=n;
        else
            ind+=1;
        while(ind<len)
        {
            ans += S[ind];
            ind+=1;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}
// } Driver Code Ends