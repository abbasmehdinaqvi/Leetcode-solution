class Solution {
public:
    string reverseWords(string s) {
        
        s += ' ';
        
        vector<string> w;
        string str = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                if(str != "")
                    w.push_back(str);
                str = "";
            }
            else
                str += s[i];
        }
        
        string st = "";
        
        for(int i = w.size() - 1; i >= 0; i--)
        {
            st += w[i];
            if(i != 0)
                st += ' ';
        }
        
        return st;
    }
};