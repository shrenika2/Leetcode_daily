class Solution {
public:
    int n, m;
    vector<vector<int>> best;

    bool dfs(int r, int c, vector<vector<int>>& grid, int health) {
        if (health <= 0) return false;

        if (r == n - 1 && c == m - 1)
            return true;

        // Already reached this cell with equal or more health
        if (best[r][c] >= health)
            return false;

        best[r][c] = health;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                int newHealth = health - grid[nr][nc];

                if (dfs(nr, nc, grid, newHealth))
                    return true;
            }
        }

        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size();
        m = grid[0].size();

        best.assign(n, vector<int>(m, -1));

        int startHealth = health - grid[0][0];

        return dfs(0, 0, grid, startHealth);
    }
};