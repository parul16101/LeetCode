class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        bool flag = false;
        if(n<=2)    return false;
        if(arr[0]>arr[1])
            return false;
        if(arr[n-2]<arr[n-1])
            return false;
        
        for(int i=1;i<=n-2;i++)
        {
            if(arr[i-1]==arr[i] || arr[i]==arr[i+1])
                return false;
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1])
            {
                if(flag)
                    return false;
                else
                    flag = true;
            }
        }
        return flag;
    }
};