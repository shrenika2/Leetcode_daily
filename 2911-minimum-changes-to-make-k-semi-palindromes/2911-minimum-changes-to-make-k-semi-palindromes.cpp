class Solution {
public:
    int getChanges(string &s, int i, int j, int d) {
        int ch = 0;
        for (int g = 0; g < d; ++g) {
            int l = i + g, r = j - (d - 1 - g);
            while (l < r) {
                if (s[l] != s[r]) ch++;
                l += d;
                r -= d;
            }
        }
        return ch;
    }

    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int ln = j - i + 1;
                for (int d = 1; d < ln; ++d) {
                    if (ln % d == 0) {
                        cost[i][j] = min(cost[i][j], getChanges(s, i, j, d));
                    }
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[n][0] = 0;

        for (int st = n - 1; st >= 0; --st) {
            for (int p = 1; p <= k; ++p) {
                for (int ed = st + 1; ed <= n - (p - 1); ++ed) {
                    if (cost[st][ed - 1] != 1e9 && dp[ed][p - 1] != 1e9) {
                        dp[st][p] = min(dp[st][p], cost[st][ed - 1] + dp[ed][p - 1]);
                    }
                }
            }
        }

        return dp[0][k];
    }
};