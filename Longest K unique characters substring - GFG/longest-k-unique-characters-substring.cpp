//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int> m;
        queue<int> q;
        
        int i = 0;
        int n = s.size();
        int len = -1;
        
        while(i<n)
        {
            q.push(s[i]);
            m[s[i]]+=1;
            
            if(m.size()==k)
            {
                //len = max(q.size(),len);
                len = max(static_cast<int>(q.size()), len);

            }
            else if(m.size()>k)
            {
                
                while(m.size()!=k)
                {
                    char front = q.front();
                    m[front] -=1;
                    
                    if(m[front]==0)
                        m.erase(front);
                    q.pop();
                    
                }
                //len = max(q.size(),len);
                len = max(static_cast<int>(q.size()), len);
            }
            i+=1;
        }
        return len;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends