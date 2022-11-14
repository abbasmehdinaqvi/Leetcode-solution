class Solution {
public:
    
    void solve(string &s, unordered_set<string> &q, int start, int end, string str, vector<string> &ans)
    {
        if(end >= s.size())
        {
            if(start >= s.size())
            {
                ans.push_back(str);
                return;
            }
            else
            {
                return;
            }
        }
        
        string word = s.substr(start, end - start + 1);
        
        if(q.count(word) && word.size() > 0)
        {
            if(str.size() == 0)
                solve(s, q, end + 1, end +1, str + word, ans);
                
            else    
                solve(s, q, end + 1, end +1, str + " " + word, ans);
        }
        
        solve(s, q, start, end +1, str, ans);
    }
    
    
    
    
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> q(wordDict.begin(), wordDict.end());
        
        vector<string> ans;
        
        solve(s, q, 0, 0, "", ans);
      
        return ans;
    }
};