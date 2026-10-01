class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        grid[i][j] = '0';

        for(int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
               grid[nr][nc] == '1') {
                dfs(grid, nr, nc);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }

        return cnt;
    }
};