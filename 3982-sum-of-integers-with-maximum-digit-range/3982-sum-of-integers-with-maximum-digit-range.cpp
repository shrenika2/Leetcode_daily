class Solution {
public:
    int maxDigitRange(vector<int>& nums) {

        int mx = 0;

        for (auto x : nums) {
            string s = to_string(x);
            sort(s.begin(), s.end());

            int range = (s.back() - '0') - (s.front() - '0');
            mx = max(mx, range);
        }

        int sum = 0;

        for (auto x : nums) {
            string s = to_string(x);
            sort(s.begin(), s.end());

            int range = (s.back() - '0') - (s.front() - '0');

            if (range == mx)
                sum += x;
        }

        return sum;
    }
};