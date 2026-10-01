class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int ini, int color) {
        int n = image.size();
        int m = image[0].size();

        image[sr][sc] = color;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nr = sr + dr[k];
            int nc = sc + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                image[nr][nc] == ini) {
                dfs(image, nr, nc, ini, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini = image[sr][sc];

        if (ini == color) return image;

        dfs(image, sr, sc, ini, color);

        return image;
    }
};