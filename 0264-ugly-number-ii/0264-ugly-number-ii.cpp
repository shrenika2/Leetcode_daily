class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> dp(n);

        dp[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i < n; i++) {
            long long x = dp[i2] * 2;
            long long y = dp[i3] * 3;
            long long z = dp[i5] * 5;

            dp[i] = min({x, y, z});

            if (dp[i] == x) i2++;
            if (dp[i] == y) i3++;
            if (dp[i] == z) i5++;
        }

        return dp[n - 1];
    }
};