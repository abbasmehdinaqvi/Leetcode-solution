class Solution {
public:
    
    bool solve(string &s, unordered_set<string> &q, int start, int end, vector<vector<int>> &dp)
    {
        
        
        
        
        if(end >= s.size())
            return start >= s.size();
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        string str = s.substr(start, end - start + 1);
        //cout<<str<<endl;
        if(q.count(str))
            return dp[start][end] = solve(s, q, end + 1, end+1, dp) || solve(s, q, start, end + 1, dp);
        
        
        return dp[start][end] = solve(s, q, start, end + 1, dp);
        
        return false;
    }
    
    
    
    
    
    
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        
        
        
        
        unordered_set<string> q(wordDict.begin(), wordDict.end());
        
        
        if(s.size() < 2)
            return q.count(s);
        
        vector<vector<int>> dp(s.size() + 2, vector<int>(s.size() + 2, -1));
        return solve(s, q, 0, 0, dp);
    }
};