class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int> comp(n, -1);

        int id = 0;
        comp[0] = id;

        for (int i = 0; i < n - 1; i++) {
            if (abs(nums[i] - nums[i + 1]) <= maxDiff) {
                comp[i + 1] = id;
            } else {
                id++;
                comp[i + 1] = id;
            }
        }

        vector<bool> ans;
        for (auto &q : queries) {
            ans.push_back(comp[q[0]] == comp[q[1]]);
        }

        return ans;
    }
};