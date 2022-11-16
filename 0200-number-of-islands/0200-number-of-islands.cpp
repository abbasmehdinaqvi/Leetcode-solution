class Solution {
public:

    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n, vector<vector<int>> &d)
    {
        
        grid[i][j] = '2';
        
        for(auto w : d)
        {
            int r = i + w[0];
            int c = j + w[1];
            
            if(r >= 0 && r < m && c >= 0 && c < n)
            {
                if(grid[r][c] == '1')
                    dfs(grid, r, c, m, n, d);
            }
        }
        
        
    }
    
    
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        
        vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                { 
                    dfs(grid, i, j, m, n, d);
                    ans++;
                }
            }
        }
        
        
        return ans;
        
    }
};