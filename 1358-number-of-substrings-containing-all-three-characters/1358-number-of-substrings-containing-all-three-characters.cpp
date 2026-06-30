class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();       
        vector<int> lp = {-1, -1, -1};
        int t = 0;
        for (int i = 0; i < len; i++) {           
            lp[s[i] - 'a'] = i;
            t += 1 + min({lp[0], lp[1], lp[2]});
        }
        return t;
    }
};