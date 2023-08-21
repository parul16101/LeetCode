//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    
	    unordered_map<int,vector<int>> adj;
	    int V = N;
	    
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<prerequisites.size();i++)
	    {
	        int a = prerequisites[i].first;
	        int b = prerequisites[i].second;
	        
	        adj[b].push_back(a);
	        
	        indegree[a] += 1;
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    
	    int count = 0;
	    
	    while(!q.empty())
	    {
	        int i = q.front();
	        count+=1;
	        q.pop();
	        
	        for(auto j:adj[i])
	        {
	           indegree[j] -= 1;
	                
	           if(indegree[j]==0)
	              q.push(j);
	            
	        }
	    }
	    
	    if(count==V)
	        return true;
	    return false;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends