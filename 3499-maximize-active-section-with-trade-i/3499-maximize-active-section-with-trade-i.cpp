class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int n = t.size();

        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        vector<pair<char,int>> v;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            v.push_back({t[i], j - i});
            i = j;
        }

        int ans = ones;

        for (int i = 1; i + 1 < (int)v.size(); i++) {
            if (v[i].first == '1' &&
                v[i - 1].first == '0' &&
                v[i + 1].first == '0') {

                ans = max(ans, ones + v[i - 1].second + v[i + 1].second);
            }
        }

        return min(ans, (int)s.size());
    }
};