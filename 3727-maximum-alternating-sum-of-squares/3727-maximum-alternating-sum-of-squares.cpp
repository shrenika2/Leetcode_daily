
class Solution {
public:
    #define ll long long

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        ll sm = 0;
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });

        for (int i = 0; i < n; i++) {
            ll x = 1LL * nums[i] * nums[i];

            if (i < (n + 1) / 2)
                sm += x;
            else
                sm -= x;
        }

        return sm;
    }
};
