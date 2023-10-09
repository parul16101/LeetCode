class Solution {
public:
    int findLeft(vector<int>& nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if((mid==0 || nums[mid-1]!=nums[mid]) && nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
                low = mid+1;
            else
                high = mid-1; 
        }
        return -1;
    }
    
    int findRight(vector<int>& nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if((mid==(n-1) || nums[mid]!=nums[mid+1]) && nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<=target)
                low = mid+1;
            else if(nums[mid]>target)
                high = mid-1; 
        }
        return -1;
    }
    
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int left = -1, right = -1;
        vector<int> ans;
        
        left = findLeft(nums,target);
        
        if(left==-1)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        right = findRight(nums,target);
        
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
};