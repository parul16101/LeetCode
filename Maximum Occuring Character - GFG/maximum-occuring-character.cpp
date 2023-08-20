//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        map<char,int> m;
        
        for(int i=0;i<str.size();i++)
        {
            m[str[i]] += 1;
        }
        
        char ans;
        int freq = INT_MIN;
        for(auto i:m)
        {
            if(i.second>freq)
                {
                    ans = i.first;
                    freq = i.second;
                }
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends