class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0;
        int p2 = 0;
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size(), m = nums2.size();
        
        while(p1<n && p2<m)
        {
            if(nums1[p1]<nums2[p2]) 
            {
                //ans.push_back(nums1[p1]);
                p1+=1;
            }
            else if(nums1[p1]>nums2[p2]) 
                {
                //ans.push_back(nums2[p2]);
                p2+=1;
            }
            else
                {
                ans.push_back(nums1[p1]);
                p1+=1;
                p2+=1;
            }
        }
        
        // while(p1<n)
        // {
        //     ans.push_back(nums1[p1]);
        //         p1+=1;
        // }
        // while(p2<m)
        // {
        //     ans.push_back(nums2[p2]);
        //         p2+=1;
        // }
        return ans;
    }
};