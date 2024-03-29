//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        if(str1.size()!=str2.size())
            return false;
        unordered_map<char,int> m;
        for(int i=0;i<str1.size();i++)
        {
            m[str1[i]]+=1;
        }
        int count = 0;
        for(int i=0;i<str2.size();i++)
        {
            if(m.find(str2[i])==m.end())
               {
                   count+=1;
                    if(count>k)
                        return false;
               }
            else
            {
                m[str2[i]]-=1;
                
                if(m[str2[i]]==0)
                    m.erase(str2[i]);
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}
// } Driver Code Ends