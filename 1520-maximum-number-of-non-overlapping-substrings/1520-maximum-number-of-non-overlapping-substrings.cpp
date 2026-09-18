class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> L(26, -1), R(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (L[s[i]-'a'] < 0) L[s[i]-'a'] = i;
            R[s[i]-'a'] = i;
        }
        vector<pair<int,int>> ivs;
        for (int i = 0; i < 26; ++i) {
            if (L[i] < 0) continue;
            int l = L[i], r = R[i]; bool ok = true;
            for (int j = l; j <= r && ok; ++j)
                if (L[s[j]-'a'] < l) ok = false; else r = max(r, R[s[j]-'a']);
            if (ok) ivs.push_back({r, l});
        }
        sort(ivs.begin(), ivs.end());
        vector<string> res; int last = -1;
        for (auto& [r, l] : ivs) if (l > last) res.push_back(s.substr(l, r - l + 1)), last = r;
        return res;
    }
};