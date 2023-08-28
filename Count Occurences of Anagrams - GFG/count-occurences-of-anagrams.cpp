//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	   
	   unordered_map<char,int> a;
	   unordered_map<char,int> b;
	   int ans = 0;
	   
	   int m = pat.size(), n = txt.size();
	   if(m>n)
	        return 0;
	        
	   for(int i=0;i<m;i++)
	   {
	       a[pat[i]]+=1;
	       b[txt[i]]+=1;
	   }
	   
	   if(a==b)
	     ans+=1;
	   
	   for(int i=1;i<=n-m;i++)
	   {
	       b[txt[i-1]] -= 1;
	       if(b[txt[i-1]]==0)
	            b.erase(txt[i-1]);
	            
	       b[txt[i+m-1]] += 1;
	       
	       if(a==b)
	         ans+=1;
	   }
	   
	   return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends