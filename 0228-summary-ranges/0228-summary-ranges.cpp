class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        map<long long int, long long int> m;
        
        for(auto i : nums)
        {
            m[i]++;
        }
        
        for(long long int  i : nums)
        {
            if(i != pow(2, 31)   && m[i + 1] == 0)
            {
                long long int k = i - 1;
                
                while(m[k] != 0)
                {
                    m[i]++;
                    m[k] = 0;
                    k--;
                }
            }
        }
        
        vector<string> ans;
        
        for(auto i : m)
        {
            
            long long int a = i.second;
            long long int b = i.first;
            
            
            
            //a = b - a;
            
            //cout<<a<<" "<<b<<endl;
            
            
            if(a > 0)
            {
                if(b - a + 1 != b)
                {
                string s = to_string(b - a + 1) + "->" + to_string(b);
                ans.push_back(s);
                }
                else
                {
                    ans.push_back(to_string(b));
                }
            }
        }
        
        return ans;
        
    }
};