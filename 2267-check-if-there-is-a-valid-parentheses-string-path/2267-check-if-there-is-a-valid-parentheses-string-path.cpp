class Solution {
public:
    int m, n;
    int dp[100][100][200];

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, 0);
    }

    bool solve(vector<vector<char>>& grid, int i, int j, int open) {
        if (i >= m || j >= n)
            return false;

        if (grid[i][j] == '(')
            open += 1;
        else
            open -= 1;

        if (open < 0)
            return false;

        if (i == m - 1 && j == n - 1 && open == 0)
            return true;

        if (dp[i][j][open] != -1)
            return dp[i][j][open];

        bool right = solve(grid, i, j + 1, open);
        bool down = solve(grid, i + 1, j, open);

        return dp[i][j][open] = right || down;
    }
};