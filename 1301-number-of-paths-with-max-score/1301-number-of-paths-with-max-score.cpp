class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& b) {
        int n = b.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        dp[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (b[i][j] == 'X') continue;
                if (i == n - 1 && j == n - 1) continue;

                int best = -1;
                int cnt = 0;

                vector<pair<int,int>> d = {
                    {i + 1, j},
                    {i, j + 1},
                    {i + 1, j + 1}
                };

                for (auto [x, y] : d) {
                    if (x >= n || y >= n) continue;
                    if (dp[x][y] == -1) continue;

                    if (dp[x][y] > best) {
                        best = dp[x][y];
                        cnt = ways[x][y];
                    } else if (dp[x][y] == best) {
                        cnt = (cnt + ways[x][y]) % MOD;
                    }
                }

                if (best == -1) continue;

                int val = 0;
                if (b[i][j] >= '0' && b[i][j] <= '9')
                    val = b[i][j] - '0';

                dp[i][j] = best + val;
                ways[i][j] = cnt;
            }
        }

        if (ways[0][0] == 0)
            return {0, 0};

        return {dp[0][0], ways[0][0]};
    }
};