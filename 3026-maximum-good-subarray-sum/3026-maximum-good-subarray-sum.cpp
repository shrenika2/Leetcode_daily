class Solution {
public:
    #define ll long long

    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll p = 0, mx = LLONG_MIN;
        unordered_map<ll, ll> mp;

        for (int x : nums) {
            if (mp.count((ll)x - k))
                mx = max(mx, p + x - mp[(ll)x - k]);

            if (mp.count((ll)x + k))
                mx = max(mx, p + x - mp[(ll)x + k]);

            if (!mp.count(x))
                mp[x] = p;
            else
                mp[x] = min(mp[x], p);

            p += x;
        }

        return mx == LLONG_MIN ? 0 : mx;
    }
};