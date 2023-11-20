class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int non_zero = 0;
        int i = 0;
        
        while(i<n)
        {
            if(nums[i]!=0)
            {
                swap(nums[non_zero], nums[i]);
                non_zero+=1;
            }
            i+=1;
        }
    }
};