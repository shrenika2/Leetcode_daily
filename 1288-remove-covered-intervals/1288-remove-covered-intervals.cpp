class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int ans = 0, mx = 0;

        for (auto &x : in) {
            if (x[1] > mx) {
                ans++;
                mx = x[1];
            }
        }

        return ans;
    }
};