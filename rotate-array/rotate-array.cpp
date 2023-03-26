class Solution {
public:
    
    void rev(vector<int>& v, int l, int h)
    {
        while(l<h)
        {
            int t = v[l];
            v[l] = v[h];
            v[h] = t;
            l+=1;
            h-=1;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % nums.size();
        if(n==1)
            return;
        rev(nums,0,n-k-1);
        rev(nums,n-k,n-1);
        rev(nums,0,n-1);
    }
};