//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}

// } Driver Code Ends


//User function Template for C++

void reverse(int arr[], int l, int r)
{
    while(l<r)
    {
        int t = arr[l];
        arr[l] = arr[r];
        arr[r] = t;
        l+=1;
        r-=1;
    }
}

void rotate(int arr[], int n)
{
    reverse(arr,0,n-2);
    reverse(arr,0,n-1);
}