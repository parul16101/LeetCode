class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int even = 0, i = 0;
        
        while(i<n)
        {
            if(nums[i]%2==0)
                {
                swap(nums[even], nums[i]);
                even+=1;
                }
            i+=1;
        }
        return nums;
    }
};