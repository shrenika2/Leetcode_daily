class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        long long fin = 0;

        if (cb <= min(c1, c2)) {
            fin = 1LL * max(n1, n2) * cb;
        }
        else if (cb <= max(c1, c2)) {
            long long mn = min(n1, n2);
            fin = 1LL * mn * cb + (n1 - mn) * min(cb, c1) + (n2 - mn) * min(cb, c2);
        }
        else if (cb <= c1 + c2) {
            long long mn = min(n1, n2);
            fin = 1LL * mn * cb + (n1 - mn) * min(cb, c1) + (n2 - mn) * min(cb, c2);
        }
        else {
            fin = 1LL * n1 * c1 + 1LL * n2 * c2;
        }

        return fin;
    }
};