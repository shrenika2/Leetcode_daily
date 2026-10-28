class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
       
        int n = grid[0].size();
         int m = grid.size();
        int mo = m;
        
        vector<bitset<1024>> dp(n);
        
        dp[0][grid[0][0]] = 1;
        
        for (int j = 1; j < n; ++j) {
            int val = grid[0][j];
            for (int k = 0; k < 1024; ++k) {
                if (dp[j - 1][k]) dp[j][k ^ val] = 1;
            }
        }
        
        for (int i = 1; i < m; ++i) {
            bitset<1024> r;
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                bitset<1024> c = dp[j];
                if (j > 0) c |= r;
                
                r.reset();
                for (int k = 0; k < 1024; ++k) {
                    if (c[k]) r[k ^ val] = 1;
                }
                dp[j] = r;
            }
        }
        
        for (int k = 0; k < 1024; ++k) {
            if (dp[n - 1][k]) return k;
        }
        
        return 0;
    }
};