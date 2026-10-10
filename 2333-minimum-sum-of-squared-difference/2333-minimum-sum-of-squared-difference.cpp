class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = 1LL * k1 + k2;
        int n = nums1.size();
        vector<int> diff(n);

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
        }

        if (sum <= k) return 0;

        int l = 0, r = 100000;

        while (l < r) {
            int mid = l + (r - l) / 2;
            long long need = 0;

            for (int x : diff)
                need += max(0, x - mid);

            if (need <= k)
                r = mid;
            else
                l = mid + 1;
        }

        long long ans = 0;
        long long used = 0;

        for (int &x : diff) {
            if (x > l) {
                used += x - l;
                x = l;
            }
            ans += 1LL * x * x;
        }

        k -= used;

        for (int &x : diff) {
            if (x == l && k > 0) {
                ans -= 1LL * x * x - 1LL * (x - 1) * (x - 1);
                x--;
                k--;
            }
        }

        return ans;
    }
};