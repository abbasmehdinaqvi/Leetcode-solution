class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int w = m.size();
        int n = m[0].size();
        
        int i = 0;
        int j = n - 1;
        
        while(i < w && j >= 0)
        {
            if(m[i][j] == t)
                return true;
            
            if(m[i][j] < t)
                i++;
            
            else
                j--;
        }
        return false;
    }
};