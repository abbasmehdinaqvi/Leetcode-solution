class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        
        int left = 0;
        int right = m[0].size();
        int top = 0;
        int bottom = m.size();
        
        vector<int> ans;
        
        while(left < right && top < bottom)
        {
            for(int i = left; i < right; i++)
                ans.push_back(m[top][i]);
            top++;
            
            for(int i = top; i < bottom; i++)
                ans.push_back(m[i][right - 1]);
            right--;
            
            if(left >= right || top >= bottom)
                break;
            
            for(int i = right - 1; i >= left; i--)
                ans.push_back(m[bottom - 1][i]);
            bottom--;
            
            for(int i = bottom - 1; i >= top; i--)
                ans.push_back(m[i][left]);
            left++;
        }
        
        return ans;
    }
};