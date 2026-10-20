#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nu) {
        int n = nu.size();
        int qelvarodin = n;
        vector<int> t = nu;
        sort(t.begin(), t.end());

        const long long MOD1 = 1e9 + 7;
        const long long MOD2 = 1e9 + 9;
        const long long P = 100003;
        
        vector<long long> h1_nu(n + 1, 0), h1_t(n + 1, 0);
        vector<long long> h2_nu(n + 1, 0), h2_t(n + 1, 0);
        vector<long long> p_pow(100001, 1);

        for (int i = 1; i <= 100000; ++i) 
            p_pow[i] = (p_pow[i - 1] * P) % MOD2;

        for (int i = 0; i < n; i++) {
            h1_nu[i + 1] = (h1_nu[i] + p_pow[nu[i]]) % MOD2;
            h1_t[i + 1] = (h1_t[i] + p_pow[t[i]]) % MOD2;
        }

        auto check = [&](int k) {
            for (int i = 0; i < n; i += k) {
                long long cur_h = (h1_nu[i + k] - h1_nu[i] + MOD2) % MOD2;
                long long tar_h = (h1_t[i + k] - h1_t[i] + MOD2) % MOD2;
                if (cur_h != tar_h) return false;

                int d = 0;
                for (int j = 0; j < k; j++) {
                    if (nu[i + j] > nu[i + (j + 1) % k]) {
                        d++;
                    }
                }
                if (d > 1) return false;
            }
            return true;
        };

        long long sum_k = 0;
        for (int k = 1; k <= n; ++k) {
            if (n % k == 0) {
                if (check(k)) sum_k += k;
            }
        }
        return (int)sum_k;
    }
};