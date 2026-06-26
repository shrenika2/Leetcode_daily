class Solution {
public:
    struct BIT {
        int n;
        vector<int> bit;

        BIT(int sz) {
            n = sz;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] == target)
                pref[i] = pref[i - 1] + 1;
            else
                pref[i] = pref[i - 1] - 1;
        }

        // Coordinate Compression
        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        BIT bit(vals.size());

        long long ans = 0;

        // Insert prefix sum = 0
        int idx = lower_bound(vals.begin(), vals.end(), pref[0]) - vals.begin() + 1;
        bit.update(idx, 1);

        for (int i = 1; i <= n; i++) {
            idx = lower_bound(vals.begin(), vals.end(), pref[i]) - vals.begin() + 1;

            // Count previous prefix sums < current
            ans += bit.query(idx - 1);

            bit.update(idx, 1);
        }

        return ans;
    }
};