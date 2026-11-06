class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [&](auto& a, auto& b) { return a[1] < b[1]; });
        vector<vector<int>> q;
        int nq = queries.size();
        for (int i = 0; i < nq; i++)
            q.push_back({queries[i], i});
        sort(q.begin(), q.end());
        vector<int> res(nq, 0);
        unordered_map<int, int> count;
        int i = 0, j = 0, t = logs.size();
        for (auto& p : q) {
            int l = p[0] - x, r = p[0], ind = p[1];
            while (i < j && logs[i][1] < l) {
                count[logs[i][0]]--;
                if (count[logs[i][0]] == 0)
                    count.erase(logs[i][0]);
                i++;
            }
            while (j < t) {
                if (logs[j][1] < l)
                    j++, i++;
                else if (logs[j][1] <= r) {
                    count[logs[j][0]]++;
                    j++;
                } else
                    break;
            }
            res[ind] = n - count.size();
        }
        return res;
    }
};