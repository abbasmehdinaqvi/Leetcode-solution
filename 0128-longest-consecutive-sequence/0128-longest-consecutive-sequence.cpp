class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        
        
        unordered_map<int, int> m;
        
        for(auto i : nums)
        {
            m[i] = 1;
        }
        
        int ans= 0;
        
        for(auto i : nums)
        {
            if(m[i - 1] == 0)
            {
                int count = 1;
                int j = i + 1;
                while(m[j++] != 0)
                    count++;
                ans = max(ans, count);
            }
        }
        
        
        
        return ans;
    }
};