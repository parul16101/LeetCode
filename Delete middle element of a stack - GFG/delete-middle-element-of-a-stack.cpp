//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void midelm(stack<int>&s, int m, int cnt)
    {
        if(cnt==m)
            {
                s.pop();
                return;
            }
        int temp = s.top();
        s.pop();
        midelm(s,m,cnt+1);
        s.push(temp);
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int m = sizeOfStack/2;
        int cnt = 0;
        
        midelm(s,m,cnt);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends