class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int a = 0, b = 1;
        int n = nums.size();
        while(b<n)
        {
            if(nums[b-1]==nums[b])
                b+=1;
            else
            {
                nums[a+1] = nums[b];
                a+=1;
                b+=1;
            }
        }
        return a+1;
    }
};