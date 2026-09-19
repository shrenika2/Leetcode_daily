class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int s = 0;
        int e = n - 1;
        int mn = INT_MAX;
        int ans = 0;
        int mx = INT_MIN;

        while(s < n) {
            mn = min(mn, p[s]);
            mx = max(mx, p[s] - mn);
            ans = max(ans, mx);
            s++;
        }

        return ans;
    }
};