#define ll long long
class Solution {
public:


    ll dp[50002][5];

    ll rec(int i, int k, vector<vector<int>> &vp, vector<int> &next) {
        int n = vp.size();
        
        if(i>=n || k<=0) return 0;

        if(dp[i][k] != -1) return dp[i][k];

        ll ans = 0;

        ans = max(ans, vp[i][2] + rec(next[i], k-1, vp, next));

        ans = max(ans, rec(i+1, k, vp, next));

        return dp[i][k] = ans;

    }


    void find(int i, int k, vector<int>& curr, vector<vector<int>> &ans, vector<int> &next, vector<vector<int>> &intervals) {
        int n = intervals.size();
        if(i >= n || k<=0)  {
            ans.push_back(curr);
            return;
        };

        ll best = dp[i][k];

        if(best == rec(next[i], k-1, intervals, next) + intervals[i][2]) {
            curr.push_back(intervals[i][3]);
            find(next[i], k-1, curr, ans, next, intervals);
            curr.pop_back();
        }

        if(best == rec(i+1, k, intervals, next)) {
            find(i+1, k, curr, ans, next, intervals);
        }
        return;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
       
        memset(dp, -1, sizeof(dp));
        int n = intervals.size();

        for(int i=0; i<n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> uniqueIntervals;

        for (auto &x : intervals) {
            if (uniqueIntervals.empty() ||
                x[0] != uniqueIntervals.back()[0] ||
                x[1] != uniqueIntervals.back()[1] ||
                x[2] != uniqueIntervals.back()[2]) {

                uniqueIntervals.push_back(x);  
            }
        }

        intervals = move(uniqueIntervals);
        n = intervals.size();

        vector<int> next(n, 0);
        for(int i=0; i<n; i++) {
            auto itr = upper_bound(intervals.begin(), intervals.end(), vector<int>{intervals[i][1], INT_MAX, INT_MAX});
            next[i] = itr - intervals.begin();
        }

        ll s = rec(0, 4, intervals, next);


        vector<int> curr;
        vector<vector<int>> ans;

        find(0, 4, curr, ans, next, intervals);

        for(auto &v: ans) {
            sort(v.begin(), v.end());
        }
        sort(ans.begin(), ans.end());
        
        return ans[0];
    }
};