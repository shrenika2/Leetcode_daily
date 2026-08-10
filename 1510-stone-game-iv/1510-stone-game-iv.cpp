class Solution {
public:
    vector<int> dp;

    bool get_max(int total) {
        if (total == 0)
            return false;

        if (dp[total] != -1)
            return dp[total];

        for (int x = 1; x * x <= total; x++) {
            int xx = x * x;

            bool opponent = get_max(total - xx);

            if (!opponent)
                return dp[total] = true;
        }

        return dp[total] = false;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n + 1, -1);
        return get_max(n);
    }
};