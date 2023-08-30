//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      int pos = 0; //
      int neg = 0, ans = INT_MIN;
      int anss = INT_MAX;
      int n = a.size();
      for(int i=0;i<n;i++)
      {
          if(a[i]<0)
          {
              neg = 1;
              break;
          }
          else
            {pos+=1;
             anss = min(anss,a[i]);
            }
      }
      
      if(pos==n)
      {
          return anss;
      }
      
      int presum = 0;
      for(int i=0;i<n;i++)
      {
          a[i] = -1*a[i];
      }
      
      
      for(int i=0;i<n;i++)
      {
          presum += a[i];
          
          if(presum<0)
            presum = 0;
            
         ans = max(ans,presum);
          
          
      }
      
      return -1*ans;
      
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends