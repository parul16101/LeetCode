class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        if(arr[0]>arr[1])
            return 0;
        if(arr[n-2]<arr[n-1])
            return (n-1);
        
        for(int i=1;i<=n-2;i++)
        {
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1])
                return i;
        }
        return 0;
    }
};