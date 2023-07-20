//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int firstOccurence(int arr[], int n , int x)
{
    int low = 0, high = n-1;
    if(arr[0]==x)
        return 0;
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        
        if(arr[mid]==x)
        {
            if(mid>0 && arr[mid]!=arr[mid-1])
                return mid;
            else
                high = mid-1;
        }
        else if(arr[mid]<x)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int secondOccurence(int arr[], int n , int x)
{
    int low = 0, high = n-1;
    if(arr[n-1]==x)
        return (n-1);
    
    while(low<=high)
    {
        int mid = (low+high)/2;
        
        if(arr[mid]==x)
        {
            if(mid<(n-1) && arr[mid]!=arr[mid+1])
                return mid;
            else
                low = mid+1;
        }
        else if(arr[mid]<x)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}



vector<int> find(int arr[], int n , int x )
{
    vector<int> ans;
    int first = firstOccurence(arr,n,x);
    int second = secondOccurence(arr,n,x);
    ans.push_back(first);
    ans.push_back(second);
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends