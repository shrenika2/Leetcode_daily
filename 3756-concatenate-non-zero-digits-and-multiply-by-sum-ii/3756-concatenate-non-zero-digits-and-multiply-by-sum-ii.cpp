#include <vector>
#include <string>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int MOD = 1e9 + 7;

        // Precomputing vectors to answer queries in O(1) time
        vector<int> nonZeroDigits(n, 0);
        vector<ll> numberUpTo(n, 0);
        vector<ll> digitSumUpTo(n, 0);
        vector<ll> powerOf10(n + 1, 0);

        // 1. Fill power of 10 array
        powerOf10[0] = 1;
        for (int i = 1; i <= n; i++) {
            powerOf10[i] = (powerOf10[i - 1] * 10) % MOD;
        }

        // 2. Fill non-zero digit count prefix array
        nonZeroDigits[0] = (s[0] != '0') ? 1 : 0;
        for (int i = 1; i < n; i++) {
            int currentDigit = s[i] - '0';
            nonZeroDigits[i] = nonZeroDigits[i - 1] + ((currentDigit != 0) ? 1 : 0);
        }

        // 3. Fill the standard cumulative number formation array
        numberUpTo[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            int currentDigit = s[i] - '0';
            if (currentDigit != 0) {
                numberUpTo[i] = (numberUpTo[i - 1] * 10 + currentDigit) % MOD;
            } else {
                numberUpTo[i] = numberUpTo[i - 1];
            }
        }

        // 4. Fill standard digit prefix sum array
        digitSumUpTo[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            int currentDigit = s[i] - '0';
            digitSumUpTo[i] = digitSumUpTo[i - 1] + currentDigit;
        }

        // Process Queries
        int q = queries.size();
        vector<int> result(q);

        for (int i = 0; i < q; i++) {
            int L = queries[i][0];
            int R = queries[i][1];

            // Finding Sum in range [L, R] using prefix sums
            ll sum = digitSumUpTo[R] - ((L == 0) ? 0 : digitSumUpTo[L - 1]);

            // Handling out-of-bounds safety for left bound elements
            ll numBefore = (L == 0) ? 0 : numberUpTo[L - 1];
            int k = nonZeroDigits[R] - ((L == 0) ? 0 : nonZeroDigits[L - 1]);

            // Formulate X for the subarray by cutting out the unwanted prefix digits mathematically
            ll x = (numberUpTo[R] - (numBefore * powerOf10[k]) % MOD + MOD) % MOD;

            // Combine X and Sum to fetch query answers
            result[i] = (x * sum) % MOD;
        }

        return result;
    }
};