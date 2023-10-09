class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int number = 0;
        vector<int> ans;
        ans = digits;
        
        int sum = 0, carry = 1;
        
        for(int i=n-1;i>=0;i--)
        {
            sum = ans[i]+carry;
            
            carry = 0;
            
            if(sum<=9)
            {
                ans[i] = sum;
                carry = 0;
                break;
            }
            else
            {
                ans[i] = 0;
                carry = 1;
            }
        }
        
        if(carry==1)
        {
            ans.insert(ans.begin(),1);
        }
        return ans;
    }
};