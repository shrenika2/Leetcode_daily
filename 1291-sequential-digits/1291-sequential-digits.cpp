class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        int l = to_string(low).size();
        int h = to_string(high).size();

        for (int len = l; len <= h; len++) {
            for (int st = 1; st + len - 1 <= 9; st++) {
                int num = 0;
                for (int d = st; d < st + len; d++) {
                    num = num * 10 + d;
                }

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};