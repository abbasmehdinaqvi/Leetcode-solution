class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size() - 1;
        
        if(n == 0)
            return 0;
        
        if(nums[0] > nums[1])
            return 0;
        
        
        if(nums[n] > nums[n - 1])
            return n;
        
        
        int l = 0;
        int r = n;
        
        while(l <= r)
        {
            int m = (l + r) / 2;
            
            if(m == 0 && nums[0] > nums[1])
                return 0;
            
            if(m == n && nums[n] > nums[n - 1])
               return n;
            
            if(nums[m] > nums[m + 1] && nums[m] > nums[m - 1])
                return m;
            
            if(nums[m] < nums[m + 1])
                l = m + 1;
            
            else
                r = m - 1;
                
        }
        
        return 0;
        
    }
};